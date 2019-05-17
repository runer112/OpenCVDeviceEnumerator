#pragma once

#ifndef DEVICEENUMERATOR_EXPORT
#define DEVICEENUMERATOR_EXPORT __declspec(dllimport)
#endif

#include <guiddef.h>

#pragma comment(lib, "strmiids")

#include <map>
#include <string>

typedef wchar_t *BSTR;

struct Device {
	int id; // This can be used to open the device in OpenCV
	std::string devicePath;
	std::string deviceName; // This can be used to show the devices to the user
};

class DEVICEENUMERATOR_EXPORT DeviceEnumerator {

public:

	DeviceEnumerator() = default;
	std::map<int, Device> getDevicesMap(const GUID deviceClass);
	std::map<int, Device> getVideoDevicesMap();
	std::map<int, Device> getAudioDevicesMap();

private:

	std::string ConvertBSTRToMBS(BSTR bstr);
	std::string ConvertWCSToMBS(const wchar_t* pstr, long wslen);

};
