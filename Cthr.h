/* --------------------------------------------------------------
    ������� ��� ��������� ������������� ��������� (������ 2.0).

    http://www.imach.uran.ru/cbignum

    Copyright 2010, �.�.�������, ���� ��� PAH.
    All Rights Reserved.

    ��� ��������������� �� �������� �������� "public domain",
    �.�. ����������� ��������� ����������, ����������� �
    ��������������� ���� ��� ������� ���������� ���������
    � ���������� �������� � ���� ��������� ����������.

    ������ ����������� ����������� ��������������� "��� ����"
    ��� �����-���� ��������, ����� ��� ���������������. ��
    ����������� ��� �� ���� ����������� ����� � ����. �����
    �� ����� ����� ��������������� �� ������ ������, �����,
    ������ ��� ����� ������ ���� ������ ��� ����� ��������
    ������������� ������� ������������ �����������.
-------------------------------------------------------------- */
#ifndef _CTHR_H
#define _CTHR_H

#ifndef __STDC__

/*
    Visual C++ & Borland C++ Builder
*/
#ifdef  _MT
#ifdef  _WIN32
#define _CTHR_PROCESS
#endif/*_WIN32*/
#ifdef  _WIN64
#define _CTHR_PROCESS
#endif/*_WIN64*/
#endif/*_MT*/

#endif/*__STDC__*/

#ifdef  _CTHR_PROCESS
#include <process.h>
#endif/*_CTHR_PROCESS*/

#endif/*_CTHR_H*/
