program USB_GPIO_Test;

{$APPTYPE CONSOLE}

{$R *.res}

uses
  System.SysUtils,
  ControlGPIO in 'ControlGPIO.pas';
var
ret:Integer;
pin_value:Word;
begin
  try
    { TODO -oUser -cConsole Main : Insert code here }
    //Scan device(must call)
    ret := VGI_ScanDevice(1);
    if ret<=0 then
      Writeln('No device connect!');
    //Open device(must call)
    ret := VGI_OpenDevice(VGI_USBGPIO,0,0);
    if ret <> ERR_SUCCESS then
      Writeln('Open device error!');
    //��GPIO_7��GPIO_8���ó��������
    ret := VGI_SetOutput(VGI_USBGPIO, 0, VGI_GPIO_PIN7 or VGI_GPIO_PIN8);
    if ret <> ERR_SUCCESS then
      Writeln('Set pin output error!')
    else
      Writeln('Set pin output success!');
    //��GPIO_7��GPIO_8����ߵ�ƽ
    ret := VGI_SetPins(VGI_USBGPIO, 0, VGI_GPIO_PIN7 or VGI_GPIO_PIN8);
    if ret <> ERR_SUCCESS then
      Writeln('Set pin high error!')
    else
      Writeln('Set pin high success!');
    //��GPIO_7��GPIO_8����͵�ƽ
    ret := VGI_ResetPins(VGI_USBGPIO, 0, VGI_GPIO_PIN7 or VGI_GPIO_PIN8);
    if ret <> ERR_SUCCESS then
      Writeln('Set pin low error!')
    else
      Writeln('Set pin low success!');
    //��GPIO_4��GPIO_5���ó���������
    ret := VGI_SetInput(VGI_USBGPIO, 0, VGI_GPIO_PIN4 or VGI_GPIO_PIN5);
    if ret <> ERR_SUCCESS then
      Writeln('Set pin input error!')
    else
      Writeln('Set pin input success!');
    //��ȡGPIO_4��GPIO_5����״̬
    ret := VGI_ReadDatas(VGI_USBGPIO, 0, VGI_GPIO_PIN4 or VGI_GPIO_PIN5, @pin_value);
    if ret <> ERR_SUCCESS then
      Writeln('Get pin data error!')
    else
      begin
        if (pin_value and VGI_GPIO_PIN4)=0 then
          Writeln('GPIO_4 is low-level!')
        else
          Writeln('GPIO_4 is high-level!');
        if (pin_value and VGI_GPIO_PIN5)=0 then
          Writeln('GPIO_5 is low-level!')
        else
          Writeln('GPIO_5 is high-level!');
      end;
    //��GPIO_4��GPIO_5�������óɿ�©ģʽ������������裬�ɵ�˫��ڣ�
    ret := VGI_SetOpenDrain(VGI_USBGPIO, 0, VGI_GPIO_PIN4 or VGI_GPIO_PIN5);
    if ret <> ERR_SUCCESS then
      Writeln('Set pin open drain error!')
    else
      Writeln('Set pin open drain success!');
    //��GPIO_4��GPIO_5����ߵ�ƽ
    ret := VGI_SetPins(VGI_USBGPIO, 0, VGI_GPIO_PIN4 or VGI_GPIO_PIN5);
    if ret <> ERR_SUCCESS then
      Writeln('Set pin high error!')
    else
      Writeln('Set pin high success!');
    //��GPIO_4��GPIO_5����͵�ƽ
    ret := VGI_ResetPins(VGI_USBGPIO, 0, VGI_GPIO_PIN4 or VGI_GPIO_PIN5);
    if ret <> ERR_SUCCESS then
      Writeln('Set pin low error!')
    else
      Writeln('Set pin low success!');
    //��ȡGPIO_4��GPIO_5����״̬
    ret := VGI_ReadDatas(VGI_USBGPIO, 0, VGI_GPIO_PIN4 or VGI_GPIO_PIN5, @pin_value);
    if ret <> ERR_SUCCESS then
      Writeln('Get pin data error!')
    else
      begin
        if (pin_value and VGI_GPIO_PIN4)=0 then
          Writeln('GPIO_4 is low-level!')
        else
          Writeln('GPIO_4 is high-level!');
        if (pin_value and VGI_GPIO_PIN5)=0 then
          Writeln('GPIO_5 is low-level!')
        else
          Writeln('GPIO_5 is high-level!');
      end;
    //Close device
    ret := VGI_CloseDevice(VGI_USBGPIO, 0);
    if ret <> ERR_SUCCESS then
      Writeln('Close device error!')
    else
      Writeln('Close device success!');
    Readln;
  except
    on E: Exception do
      Writeln(E.ClassName, ': ', E.Message);
  end;
end.