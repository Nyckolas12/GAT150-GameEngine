#pragma once
#include <rapidjson/document.h>
#include "Math/Vector2.h"
#include "Renderer/Color.h"
#include <string>

#define READ_DATA(value, data) Json::Read(value, #data, data) 


namespace Json
{
bool Load(const std::string& filename, rapidjson::Document& document);
bool Read(const rapidjson::Value& value, const std::string& name, int& data);
bool Read(const rapidjson::Value& value, const std::string& name, bool& data);
bool Read(const rapidjson::Value& value, const std::string& name, float& data);
bool Read(const rapidjson::Value& value, const std::string& name, std::string& data);
bool Read(const rapidjson::Value& value, const std::string& name, class Vector2& data);
bool Read(const rapidjson::Value& value, const std::string& name, class Color& data);
}