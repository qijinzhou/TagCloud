#pragma once

class CanvasRenderer
{
public:
	CanvasRenderer(Microsoft::Graphics::Canvas::CanvasDrawingSession^ session);

	void Render(Microsoft::Graphics::Canvas::Text::CanvasTextLayout^ layout, float x, float y);

private:
	Microsoft::Graphics::Canvas::CanvasDrawingSession^ m_session;
};
