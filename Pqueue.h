#pragma once
#include <iostream>

using namespace std;

constexpr auto START_LINE_PRIORITY = __LINE__;
enum class Priority {
	high = 1,
	medium,
	low
};
constexpr auto PRIORITY_COUNT = __LINE__ - START_LINE_PRIORITY - 3;
const string PRIORITY_NAMES[] = { "high", "medium", "low" };

typedef int InfoType;


class Priority_Queue
{
private:
	struct QItem
	{
		InfoType info;
		Priority status;
		QItem* next;
		QItem(InfoType _info, Priority prioritet_) : info(_info), status(prioritet_), next(NULL) {}
	};
	QItem* front, * high_rear, * medium_rear, * low_rear;
	int size, size_high, size_medium, size_low;

	void Erase();
	void Clone(const Priority_Queue&);
	void move(QItem*&, QItem*&);
	void move(Priority_Queue&& other);
public:

	Priority_Queue() :front(NULL), high_rear(NULL), medium_rear(NULL), low_rear(NULL), size(0) {};
	Priority_Queue(const Priority_Queue&);
	Priority_Queue(Priority_Queue&&) noexcept;

	~Priority_Queue();

	Priority_Queue& operator = (const Priority_Queue&);
	Priority_Queue& operator = (Priority_Queue&&) noexcept;

	int GetSize()const;
	int GetSizeInHigh()const;
	int GetSizeInMedium()const;
	int GetSizeInLow()const;
	bool IsEmpty() const;
	void Push(InfoType Ainfo, Priority astatus);
	bool pop();
	InfoType GetFirst()const;
	string GetFirstPriority()const;
	InfoType operator [](int M)const;
};

