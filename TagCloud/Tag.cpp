#include "pch.h"
#include "Tag.h"

uint32_t TagCollection::GetTotalCount() const
{
	uint32_t count = 0;
	for (const auto& tag : m_tags)
		count += tag.count;
	return count;
}

uint32_t TagCollection::GetMaxCount() const
{
	uint32_t max = 0;
	for (const auto& tag : m_tags)
		max = std::max(max, tag.count);
	return max;
}

void TagCollection::Add(Tag&& tag)
{
	m_tags.push_back(std::move(tag));
}

void TagCollection::Set(std::vector<Tag>&& tags)
{
	m_tags = std::move(tags);
}

void TagCollection::SortAscending()
{
	std::sort(m_tags.begin(), m_tags.end(), [](const auto& tag1, const auto& tag2) { return tag1.count < tag2.count; });
}

void TagCollection::SortDescending()
{
	std::sort(m_tags.begin(), m_tags.end(), [](const auto& tag1, const auto& tag2) { return tag2.count < tag1.count; });
}
