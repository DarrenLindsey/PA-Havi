#pragma once

#include <sapi.h>
#include<iostream>
#include <string>
using namespace std;
class BasicVoice
{
protected:
	int choice;
	ISpVoice* pVoice;
	HRESULT hr, a;
	wstring input;
public:
	BasicVoice() {
		pVoice = NULL;
		input = L"";
		a = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);//HRESULT CoInitializeEx(LPVOID pvReserved, DWORD dwCoInit);
		if (FAILED(a))
		{
			cout << "ERROR 404 FAILED INITIALIZING COM\n";
			exit(1);
		}
		hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)&pVoice);
	}
	virtual void setSpeech();
	virtual void byeSpeech() = 0;
	virtual void outSpeech();
	virtual ~BasicVoice() {
		::CoUninitialize();
		delete pVoice;
	}
};