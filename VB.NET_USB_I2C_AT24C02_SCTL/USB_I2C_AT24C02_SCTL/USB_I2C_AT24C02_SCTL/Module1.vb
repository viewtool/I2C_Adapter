﻿Module Module1

    Sub Main()
        Dim ret As Int32
        'Scan device
        ret = VII_ScanDevice(1)
        If ret <= 0 Then
            System.Console.WriteLine("No device connected!")
            Return
        End If
        'Open device
        ret = VII_OpenDevice(ControlI2C.VII_USBI2C, 0, 0)
        If ret <> ControlI2C.SUCCESS Then
            System.Console.WriteLine("Open device error!")
            Return
        End If
        'Initialize device(hardware mode)
        Dim I2C_Config As ControlI2C.VII_INIT_CONFIG
        I2C_Config.AddrType = ControlI2C.VII_ADDR_7BIT
        I2C_Config.ClockSpeed = 400000
        I2C_Config.ControlMode = ControlI2C.VII_SCTL_MODE
        I2C_Config.MasterMode = ControlI2C.VII_MASTER
        I2C_Config.SubAddrWidth = ControlI2C.VII_SUB_ADDR_1BYTE
        ret = VII_InitI2C(ControlI2C.VII_USBI2C, 0, 0, I2C_Config)
        If ret <> ControlI2C.SUCCESS Then
            System.Console.WriteLine("Initialize device error!")
            Return
        End If
        ' Configure time
        Dim I2C_TimeConfig As ControlI2C.VII_TIME_CONFIG
        I2C_TimeConfig.tSU_STA = 5
        I2C_TimeConfig.tHD_STA = 4
        I2C_TimeConfig.tLOW = 5    
        I2C_TimeConfig.tHIGH = 5
        I2C_TimeConfig.tSU_DAT = 1
        I2C_TimeConfig.tSU_STO = 4
        I2C_TimeConfig.tBuf = 5    
        ret = VII_TimeConfig(ControlI2C.VII_USBI2C, 0, 0, I2C_TimeConfig)
        If ret <> ControlI2C.SUCCESS Then
            System.Console.WriteLine("Set time error!")
            Return
        End If
        ' Write data to 0x00
        Dim write_buffer(8) As Byte
        Dim device_addr As UInt16
        Dim sub_addr As UInt32
        Dim i As Integer
        For i = 0 To 7
            write_buffer(i) = CType(i, Byte)
        Next i
        device_addr = &HA0
        sub_addr = &H8
        ret = VII_WriteBytes(ControlI2C.VII_USBI2C, 0, 0, device_addr, sub_addr, write_buffer, 8)
        If ret <> ControlI2C.SUCCESS Then
            System.Console.WriteLine("Write data error!")
            Return
        Else
            System.Console.WriteLine("Write data success!")
        End If
        'Delay to ensure write complete
        Threading.Thread.Sleep(10)
        ' Read data from 0x00
        Dim read_buffer(8) As Byte
        ret = VII_ReadBytes(ControlI2C.VII_USBI2C, 0, 0, device_addr, sub_addr, read_buffer, 8)
        If ret <> ControlI2C.SUCCESS Then
            System.Console.WriteLine("Read data error!" + ret.ToString)
            Return
        Else
            System.Console.WriteLine("Read data:")
            For i = 0 To 7
                System.Console.Write(" " + read_buffer(i).ToString)
            Next i
        End If
    End Sub

End Module
