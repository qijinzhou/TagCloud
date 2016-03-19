#pragma once

struct Tag
{
	std::wstring tag;
	uint32_t count;
};

class TagCollection
{
public:
	uint32_t GetTotalCount() const;

	void AddTag(Tag&& tag);

	void SortAscending();
	void SortDescending();

private:
	std::vector<Tag> m_tags;
};
