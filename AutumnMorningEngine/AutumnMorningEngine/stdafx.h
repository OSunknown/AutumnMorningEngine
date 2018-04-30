// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once


#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
#define _CRT_SECURE_NO_WARNINGS
// Windows ��� ����:
#include <windows.h>
#include <stdio.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <math.h>
#include <intrin.h>

// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.
#define KINDA_SMALL_NUMBER 1.e-4f
#define FORCEINLINE __forceinline
#define PI    (3.14159265358979323846)

FORCEINLINE float Deg2Rad(float degree)
{
	return (float)((degree) * (PI / 180.0));
}