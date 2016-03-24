#include "pch.h"
#include "CanvasRenderer.h"

using namespace Windows::UI;

using namespace Microsoft::Graphics::Canvas;
using namespace Microsoft::Graphics::Canvas::Text;

CanvasRenderer::CanvasRenderer(CanvasDrawingSession^ session) :
	m_session(session)
{
}

void CanvasRenderer::Render(CanvasTextLayout^ layout, float x, float y)
{
	m_session->DrawTextLayout(layout, x, y, Colors::Black);
}
