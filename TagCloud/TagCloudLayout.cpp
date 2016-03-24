#include "pch.h"
#include "TagCloudLayout.h"
#include "CanvasRenderer.h"
#include "Tag.h"

using namespace Microsoft::Graphics::Canvas;
using namespace Microsoft::Graphics::Canvas::Text;
using namespace Platform;

TagCloudLayout::TagCloudLayout(ICanvasResourceCreator^ resourceCreator) :
	m_resourceCreator(resourceCreator)
{
}

void TagCloudLayout::Layout(const TagCollection& tags)
{
	tags.Enumerate([this](const auto& tag)
	{
		m_layouts.emplace_back();
		auto& layout = m_layouts.back();

		layout.format = ref new CanvasTextFormat();
		layout.format->FontSize = 72.0f;

		layout.layout = ref new CanvasTextLayout(m_resourceCreator, ref new String(tag.tag.c_str()), layout.format, 1000.0f, 100.f);
	});
}

void TagCloudLayout::Render(CanvasRenderer& renderer)
{
	for (const auto& layout : m_layouts)
		renderer.Render(layout.layout, 100, 100);
}
