#include "pch.h"
#include "CanvasRenderer.h"

using namespace Windows::Foundation;
using namespace Windows::UI;

using namespace Microsoft::Graphics::Canvas;
using namespace Microsoft::Graphics::Canvas::Text;

CanvasRenderer::CanvasRenderer(CanvasDrawingSession^ session) :
	m_session(session)
{
}

void CanvasRenderer::Render(CanvasTextLayout^ layout, const Point& point)
{
	auto color = ColorHelper::FromArgb(255, static_cast<uint8_t>(m_colorDist(m_random)), static_cast<uint8_t>(m_colorDist(m_random)), static_cast<uint8_t>(m_colorDist(m_random)));
	m_session->DrawTextLayout(layout, point.X, point.Y, color);

	// Debug
	auto drawBounds = layout->DrawBounds;
	m_session->DrawRectangle(point.X + drawBounds.X, point.Y + drawBounds.Y, drawBounds.Width, drawBounds.Height, Colors::Red);
}
