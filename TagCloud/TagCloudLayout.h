#pragma once

class CanvasRenderer;
class TagCollection;

struct TagLayout
{
	Microsoft::Graphics::Canvas::Text::CanvasTextFormat^ format;
	Microsoft::Graphics::Canvas::Text::CanvasTextLayout^ layout;
};

class TagCloudLayout
{
public:
	TagCloudLayout(Microsoft::Graphics::Canvas::ICanvasResourceCreator^ resourceCreator);

	void Layout(const TagCollection& tags);

	void Render(CanvasRenderer& renderer);

private:
	Microsoft::Graphics::Canvas::ICanvasResourceCreator^ m_resourceCreator;
	std::vector<TagLayout> m_layouts;
};
