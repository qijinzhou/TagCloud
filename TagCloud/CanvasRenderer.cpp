#include "pch.h"
#include "CanvasRenderer.h"

using namespace Windows::UI;

using namespace Microsoft::Graphics::Canvas;

CanvasRenderer::CanvasRenderer(CanvasDrawingSession^ session) :
	m_session(session)
{
}

void CanvasRenderer::Render()
{
	m_session->FillCircle(200, 200, 50, Colors::Red);
}
