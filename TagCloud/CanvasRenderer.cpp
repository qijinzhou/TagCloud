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
	m_session->DrawTextLayout(layout, point.X, point.Y, Colors::Black);
}
