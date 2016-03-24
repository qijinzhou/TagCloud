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

	void Add(Tag&& tag);
	void Set(std::vector<Tag>&& tags);

	void SortAscending();
	void SortDescending();

	template<class EnumerateFunction>
	void Enumerate(EnumerateFunction enumerate) const
	{
		for (const auto& tag : m_tags)
			enumerate(tag);
	}

private:
	std::vector<Tag> m_tags;
};
