#pragma once
#include <string>
#include <memory>

class Resource
{
public:
	Resource() = default;
	~Resource() = default;

	virtual bool Create(std::string name, ...) = 0;
};
template<typename T>
using res_t = std::shared_ptr<T>;