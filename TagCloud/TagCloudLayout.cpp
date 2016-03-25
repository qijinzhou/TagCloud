#include "pch.h"
#include "TagCloudLayout.h"
#include "CanvasRenderer.h"
#include "Tag.h"

using namespace Microsoft::Graphics::Canvas;
using namespace Microsoft::Graphics::Canvas::Text;
using namespace Platform;
using namespace Windows::Foundation;

constexpr float PI = 3.14159265359f;

bool Intersects(const Point& posA, const Size& sizeA, const Point& posB, const Size& sizeB)
{
	return posA.X < posB.Y + sizeB.Width && posB.X < posA.X + sizeA.Width && posA.Y < posB.Y + sizeB.Height && posB.Y < posA.Y + sizeA.Height;
}

bool Intersects(const Point& posA, const Size& sizeA, Rect& rectB)
{
	return posA.X < rectB.Right && rectB.Left < posA.X + sizeA.Width && posA.Y < rectB.Bottom && rectB.Top < posA.Y + sizeA.Height;
}

TagCloudLayout::TagCloudLayout(ICanvasResourceCreator^ resourceCreator) :
	m_resourceCreator(resourceCreator)
{
}

void TagCloudLayout::Layout(const TagCollection& tags, const Size& canvasSize)
{
	uint32_t maxCount = tags.GetMaxCount();
	tags.Enumerate([this, maxCount](const auto& tag)
	{
		m_layouts.emplace_back();
		auto& layout = m_layouts.back();

		layout.format = ref new CanvasTextFormat();
		layout.format->FontSize = tag.count * 200.0f / maxCount;

		layout.layout = ref new CanvasTextLayout(m_resourceCreator, ref new String(tag.tag.c_str()), layout.format, 1000.0f, 100.f);
	});

	std::vector<Rect> layoutBounds;
	layoutBounds.reserve(m_layouts.size());

	const float separation = 10;
	const float maxRadius = std::min(canvasSize.Width, canvasSize.Height);
	const float maxT = std::ceil(maxRadius / separation) * PI;
	const float arcToChordFactor = 1.5f;
	const float spiralScaling = maxRadius / maxT;

	for (auto& layout : m_layouts)
	{
		Rect bounds = layout.layout->DrawBounds;
		Size size = { bounds.Width, bounds.Height };
		Point point;
		for (float t = 0; t < maxT; t += arcToChordFactor * separation / (spiralScaling * t + separation))
		{
			point = { spiralScaling * t * std::cos(t), spiralScaling * t * std::sin(t) };
			bool goodFit = true;
			for (auto& layoutBound : layoutBounds)
			{
				goodFit = !Intersects(point, size, layoutBound);
				if (!goodFit)
					break;
			}
			if (goodFit)
				break;
		}

		bounds.X = point.X;
		bounds.Y = point.Y;
		layout.point = point;
		layoutBounds.emplace_back(bounds);
	}

	for (auto& layout : m_layouts)
	{
		layout.point.X += canvasSize.Width / 2 - layout.layout->DrawBounds.X;
		layout.point.Y += canvasSize.Height / 2 - layout.layout->DrawBounds.Y;
	}
}

void TagCloudLayout::Render(CanvasRenderer& renderer)
{
	for (const auto& layout : m_layouts)
		renderer.Render(layout.layout, layout.point);
}
