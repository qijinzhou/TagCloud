#pragma once

class CanvasRenderer
{
public:
	CanvasRenderer(Microsoft::Graphics::Canvas::CanvasDrawingSession^ session);

	void Render(Microsoft::Graphics::Canvas::Text::CanvasTextLayout^ layout, const Windows::Foundation::Point& point);

private:
	Microsoft::Graphics::Canvas::CanvasDrawingSession^ m_session;
};
