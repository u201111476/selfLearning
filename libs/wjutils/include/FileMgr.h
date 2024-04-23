#ifndef _WJ_FILE_MGR_H_
#define _WJ_FILE_MGR_H_

#pragma once

#ifdef WJ_EXPORT
#define WJAPI __declspec(dllexport)
#else
#define WJAPI __declspec(dllimport)
#endif

#include <string>

class WJAPI FileMgr
{
public:
	/// @brief 获取可执行文件的路径
	/// @return 可执行文件路径字符串
	static std::string GetExecutableFilePath();
	/// @brief 判断文件是否存在
	/// @param filePath 文件路径
	/// @return 如果文件存在返回true
	static bool IsFileExist(const char* filePath);
	/// @brief 判断文件是否存在
	/// @param filePath 文件路径
	/// @return 如果文件存在返回true
	static bool IsFileExist(const std::string& filePath);
};

#endif
