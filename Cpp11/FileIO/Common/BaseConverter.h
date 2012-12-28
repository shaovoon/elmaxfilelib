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
	virtual ~BaseConverter(void);
	//! Convert the boolean into string
	//!
	//! @param dest is the string to be set
	//! @param val is the source boolean value to convert from
	//! @returns true if successful
	virtual bool SetBool(std::wstring& dest, bool val);
	//! Convert the character into string
	//!
	//! @param dest is the string to be set
	//! @param val is the source character value to convert from
	//! @returns true if successful
	virtual bool SetInt8(std::wstring& dest, char val);
	//! Convert the short integer into string
	//!
	//! @param dest is the string to be set
	//! @param val is the source short integer value to convert from
	//! @returns true if successful
	virtual bool SetInt16(std::wstring& dest, short val);
	//! Convert the 32bit integer into string
	//!
	//! @param dest is the string to be set
	//! @param val is the source 32bit integer value to convert from
	//! @returns true if successful
	virtual bool SetInt32(std::wstring& dest, int val);
#ifdef __APPLE__
	//! Convert the size_t integer into string
	//!
	//! @param dest is the string to be set
	//! @param val is the source size_t integer value to convert from
	//! @returns true if successful
	virtual bool SetSizeT(std::wstring& dest, size_t val);
#endif
	//! Convert the 64bit integer into string
	//!
	//! @param dest is the string to be set
	//! @param val is the source 64bit integer value to convert from
	//! @returns true if successful
	virtual bool SetInt64(std::wstring& dest, ELMAX_INT64 val);
	//! Convert the unsigned character into string
	//!
	//! @param dest is the string to be set
	//! @param val is the source unsigned character value to convert from
	//! @returns true if successful
	virtual bool SetUInt8(std::wstring& dest, unsigned char val);
	//! Convert the unsigned short into string
	//!
	//! @param dest is the string to be set
	//! @param val is the source unsigned short value to convert from
	//! @returns true if successful
	virtual bool SetUInt16(std::wstring& dest, unsigned short val);
	//! Convert the unsigned 32bit integer into string
	//!
	//! @param dest is the string to be set
	//! @param val is the source unsigned 32bit integer value to convert from
	//! @returns true if successful
	virtual bool SetUInt32(std::wstring& dest, unsigned int val);
	//! Convert the unsigned 64bit integer into string
	//!
	//! @param dest is the string to be set
	//! @param val is the source unsigned 64bit integer value to convert from
	//! @returns true if successful
	virtual bool SetUInt64(std::wstring& dest, unsigned ELMAX_INT64 val);
	//! Convert the float into string
	//!
	//! @param dest is the string to be set
	//! @param val is the source float value to convert from
	//! @returns true if successful
	virtual bool SetFloat(std::wstring& dest, float val);
	//! Convert the double into string
	//!
	//! @param dest is the string to be set
	//! @param val is the source double value to convert from
	//! @returns true if successful
	virtual bool SetDouble(std::wstring& dest, double val);
	//! Set the wide string into string
	//!
	//! @param dest is the string to be set
	//! @param val is the source wide string value to set from
	//! @returns true if successful
	virtual bool SetString(std::wstring& dest, const std::wstring& val);
	//! Set the ascii string into string
	//!
	//! @param dest is the string to be set
	//! @param val is the source ascii string value to set from
	//! @returns true if successful
	virtual bool SetString(std::wstring& dest, const std::string& val);
	//! Convert the unsigned integer into hexadecimal representation
	//!
	//! @param dest is the string to be set
	//! @param val is the source GUID value to convert from
	//! @returns true if successful
	virtual bool SetHex(std::wstring& dest, unsigned int val, bool bAddPrefix);
	//! Convert the string into boolean ("true" or "yes" or "1" or "ok" get true value 
	//! while "false" or "no" or "0" or "cancel" get false value)
	//!
	//! @param src is the source string to convert from
	//! @param defaultVal is the default boolean value to use if src is invalid or empty
	//! @param val is the destination boolean value to be set
	//! @returns true if successful
	virtual bool GetBool(const std::wstring& src, bool defaultVal, bool& val);
	//! Convert the string into character
	//!
	//! @param src is the source string to convert from
	//! @param val is the destination character value to be set
	//! @returns true if successful
	virtual bool GetInt8(const std::wstring& src, char& val);
	//! Convert the string into short integer
	//!
	//! @param src is the source string to convert from
	//! @param val is the destination short integer value to be set
	//! @returns true if successful
	virtual bool GetInt16(const std::wstring& src, short& val);
	//! Convert the string into 32bit integer
	//!
	//! @param src is the source string to convert from
	//! @param val is the destination 32bit integer value to be set
	//! @returns true if successful
	virtual bool GetInt32(const std::wstring& src, int& val);
#ifdef __APPLE__
	//! Convert the string into size_t integer
	//!
	//! @param src is the source string to convert from
	//! @param val is the destination size_t integer value to be set
	//! @returns true if successful
	virtual bool GetSizeT(const std::wstring& src, size_t& val);
#endif
	//! Convert the string into 64bit integer
	//!
	//! @param src is the source string to convert from
	//! @param val is the destination 64bit integer value to be set
	//! @returns true if successful
	virtual bool GetInt64(const std::wstring& src, ELMAX_INT64& val);
	//! Convert the string into unsigned character
	//!
	//! @param src is the source string to convert from
	//! @param val is the destination unsigned character value to be set
	//! @returns true if successful
	virtual bool GetUInt8(const std::wstring& src, unsigned char& val);
	//! Convert the string into unsigned short
	//!
	//! @param src is the source string to convert from
	//! @param val is the destination unsigned short value to be set
	//! @returns true if successful
	virtual bool GetUInt16(const std::wstring& src, unsigned short& val);
	//! Convert the string into unsigned 32bit integer
	//!
	//! @param src is the source string to convert from
	//! @param val is the destination unsigned 32bit integer value to be set
	//! @returns true if successful
	virtual bool GetUInt32(const std::wstring& src, unsigned int& val);
	//! Convert the string into unsigned 64bit integer
	//!
	//! @param src is the source string to convert from
	//! @param val is the destination unsigned 64bit integer value to be set
	//! @returns true if successful
	virtual bool GetUInt64(const std::wstring& src, unsigned ELMAX_INT64& val);
	//! Convert the string into float
	//!
	//! @param src is the source string to convert from
	//! @param defaultVal is the default float value to use if src is invalid or empty
	//! @param val is the destination float value to be set
	//! @returns true if successful
	virtual bool GetFloat(const std::wstring& src, float& val);
	//! Convert the string into double
	//!
	//! @param src is the source string to convert from
	//! @param defaultVal is the default double value to use if src is invalid or empty
	//! @param val is the destination double value to be set
	//! @returns true if successful
	virtual bool GetDouble(const std::wstring& src, double& val);
	//! Set the string into wide string
	//!
	//! @param src is the source string to convert from
	//! @param defaultVal is the default wide string value to use if src is invalid or empty
	//! @param val is the destination wide string value to be set
	//! @returns true if successful
	virtual bool GetString(const std::wstring& src, const std::wstring& defaultVal, std::wstring& val);
	//! Convert the string into ascii string
	//!
	//! @param src is the source string to convert from
	//! @param defaultVal is the default ascii string value to use if src is invalid or empty
	//! @param val is the destination ascii string value to be set
	//! @returns true if successful
	virtual bool GetString(const std::wstring& src, const std::string& defaultVal, std::string& val);
	//! Convert the hexadecimal string into unsigned integer
	//!
	//! @param src is the source string to convert from
	//! @param defaultVal is the default wide string value to use if src is invalid or empty
	//! @param val is the destination wide string value to be set
	//! @returns true if successful
	virtual bool ReadHex(const std::wstring& src, unsigned int defaultVal, unsigned int& val);

private:
	//! Helper method to check the string is a hexadecimal
	//!
	//! @param str is the string to check
	//! @returns true if str is all hexadecimal characters
	static bool CheckHexString(const std::wstring& str);

	static bool IsSignedInteger(const std::wstring& str);
	static bool IsUnsignedInteger(const std::wstring& str);
	static bool IsFloat(const std::wstring& str);
	static std::string ConvToString(const std::wstring& text);

};

} // ns Elmax