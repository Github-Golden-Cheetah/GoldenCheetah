/* 
 * Copyright (c) 2008 Sean C. Rhea (srhea@srhea.net)
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _GC_PT_D2XX_h
#define _GC_PT_D2XX_h 1

#include "Device.h"
#ifdef WIN32
    #include <windows.h>
    #include "../ftdi/FTD2XX.H"
#else
    #include <D2XX/ftd2xx.h>
#endif

class D2XX : public Device
{
    D2XX(const D2XX &);
    D2XX& operator=(const D2XX &);

    FT_DEVICE_LIST_INFO_NODE info;
    FT_HANDLE ftHandle;
    bool isOpen;
    D2XX(const FT_DEVICE_LIST_INFO_NODE &info);

    public:

    static QVector<DevicePtr> myListDevices(QString &err);

    virtual ~D2XX();
    virtual bool open(QString &err);
    virtual void close();
    virtual int read(void *buf, size_t nbyte, QString &err);
    virtual int write(void *buf, size_t nbyte, QString &err);
    virtual QString name() const;
};

#endif // _GC_PT_D2XX_h

