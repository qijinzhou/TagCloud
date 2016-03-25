#pragma once

class CanvasRenderer
{
public:
	CanvasRenderer(Microsoft::Graphics::Canvas::CanvasDrawingSession^ session);

	void Render(Microsoft::Graphics::Canvas::Text::CanvasTextLayout^ layout, const Windows::Foundation::Point& point);

private:
	Microsoft::Graphics::Canvas::CanvasDrawingSession^ m_session;
	std::mt19937 m_random{ 12345 };
	std::uniform_int_distribution<uint16_t> m_colorDist{ 0, 255 };
};
