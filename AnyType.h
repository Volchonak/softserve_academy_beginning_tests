#include <variant>
#include <typeinfo>
#pragma once

using variant_fundamental = std::variant<char, int, long, long long, float, double, bool>;


class AnyType
{
public:
	AnyType(char data) noexcept : m_data(data) {};
	AnyType(int data) noexcept : m_data(data) {};
	AnyType(long data) noexcept : m_data(data) {};
	AnyType(long long data) noexcept : m_data(data) {};
	AnyType(double data) noexcept : m_data(data) {};
	AnyType(bool data) noexcept : m_data(data) {};
	AnyType(const AnyType& other) noexcept;
	AnyType(AnyType&& old) noexcept;
	AnyType() = delete;
	~AnyType() noexcept;
	AnyType& operator=(const AnyType& other) noexcept;
	AnyType& operator=(char value) noexcept;
	AnyType& operator=(int value) noexcept;
	AnyType& operator=(long value) noexcept;
	AnyType& operator=(long long value) noexcept;
	AnyType& operator=(double value) noexcept;
	AnyType& operator=(bool value) noexcept;

	void Swap(AnyType& other) noexcept;
	const char* get_type() const noexcept;
	char get_char()const;
	int get_int()const;
	long get_long()const;
	long long get_long_long()const;
	double get_double()const;
	bool get_bool()const;
	void set_data(char value);
	void set_data(int value);
	void set_data(long value);
	void set_data(long long value);
	void set_data(double value);
	void set_data(bool value);

private:
	variant_fundamental m_data;
};