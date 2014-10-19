#pragma once

#include <string>
#include "Common.h"

namespace Elmax
{
//! Class to convert values to and fro string
class BaseConverter
{
public:
	//! Default constructor
	BaseConverter(void);
	//! Virtual destructor
	~BaseConverter(void);
	//! Convert the boolean into string
	//!
	//! @param dest is the string to be set
	//! @param val is the source boolean value to convert from
	//! @returns true if successful
	static bool SetBool(std::wstring& dest, bool val);
	//! Set the wide string into string
	//!
	//! @param dest is the string to be set
	//! @param val is the source wide string value to set from
	//! @returns true if successful
	static bool SetString(std::wstring& dest, const std::wstring& val);
	//! Set the ascii string into string
	//!
	//! @param dest is the string to be set
	//! @param val is the source ascii string value to set from
	//! @returns true if successful
	static bool SetString(std::wstring& dest, const std::string& val);
	//! Convert the unsigned integer into hexadecimal representation
	//!
	//! @param dest is the string to be set
	//! @param val is the source GUID value to convert from
	//! @returns true if successful
	static bool SetHex(std::wstring& dest, unsigned int val, bool bAddPrefix);
	//! Convert the string into boolean ("true" or "yes" or "1" or "ok" get true value 
	//! while "false" or "no" or "0" or "cancel" get false value)
	//!
	//! @param src is the source string to convert from
	//! @param defaultVal is the default boolean value to use if src is invalid or empty
	//! @param val is the destination boolean value to be set
	//! @returns true if successful
	static bool GetBool(const std::wstring& src, bool defaultVal, bool& val);
	//! Set the string into wide string
	//!
	//! @param src is the source string to convert from
	//! @param defaultVal is the default wide string value to use if src is invalid or empty
	//! @param val is the destination wide string value to be set
	//! @returns true if successful
	static bool GetString(const std::wstring& src, const std::wstring& defaultVal, std::wstring& val);
	//! Convert the string into ascii string
	//!
	//! @param src is the source string to convert from
	//! @param defaultVal is the default ascii string value to use if src is invalid or empty
	//! @param val is the destination ascii string value to be set
	//! @returns true if successful
	static bool GetString(const std::wstring& src, const std::string& defaultVal, std::string& val);
	//! Convert the hexadecimal string into unsigned integer
	//!
	//! @param src is the source string to convert from
	//! @param defaultVal is the default wide string value to use if src is invalid or empty
	//! @param val is the destination wide string value to be set
	//! @returns true if successful
	static bool ReadHex(const std::wstring& src, unsigned int defaultVal, unsigned int& val);

	static std::string ConvToString(const std::wstring& text);
	static std::wstring ConvToString(const std::string& text);

private:
	//! Helper method to check the string is a hexadecimal
	//!
	//! @param str is the string to check
	//! @returns true if str is all hexadecimal characters
	static bool CheckHexString(const std::wstring& str);

	static bool IsSignedInteger(const std::wstring& str);
	static bool IsUnsignedInteger(const std::wstring& str);
	static bool IsFloat(const std::wstring& str);

};

} // ns Elmax