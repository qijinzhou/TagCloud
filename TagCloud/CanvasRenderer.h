#pragma once

class CanvasRenderer
{
public:
	CanvasRenderer(Microsoft::Graphics::Canvas::CanvasDrawingSession^ session);

	void Render();

private:
	Microsoft::Graphics::Canvas::CanvasDrawingSession^ m_session;
};
