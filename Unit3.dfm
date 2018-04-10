object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'KtoKsoSrednim'
  ClientHeight = 154
  ClientWidth = 435
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 24
    Width = 76
    Height = 13
    Caption = #1042#1093#1086#1076#1085#1086#1081' '#1092#1072#1081#1083':'
  end
  object Label2: TLabel
    Left = 16
    Top = 64
    Width = 84
    Height = 13
    Caption = #1042#1099#1093#1086#1076#1085#1086#1081' '#1092#1072#1081#1083':'
  end
  object Label3: TLabel
    Left = 121
    Top = 123
    Width = 3
    Height = 13
    Visible = False
  end
  object Label4: TLabel
    Left = 16
    Top = 123
    Width = 99
    Height = 13
    Caption = #1042#1088#1077#1084#1103' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1103':'
    Visible = False
  end
  object Edit1: TEdit
    Left = 98
    Top = 21
    Width = 215
    Height = 21
    TabOrder = 0
    TextHint = #1042#1099#1073#1077#1088#1080#1090#1077' '#1092#1072#1081#1083' '#1092#1086#1088#1084#1072#1090#1072' .k'
  end
  object Button1: TButton
    Left = 335
    Top = 19
    Width = 75
    Height = 25
    Caption = '...'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit2: TEdit
    Left = 98
    Top = 61
    Width = 215
    Height = 21
    TabOrder = 2
    TextHint = #1059#1082#1072#1078#1080#1090#1077' '#1080#1084#1103' '#1074#1099#1093#1086#1076#1085#1086#1075#1086' '#1092#1072#1081#1083#1072
  end
  object Button2: TButton
    Left = 335
    Top = 96
    Width = 75
    Height = 33
    Caption = #1047#1072#1087#1091#1089#1090#1080#1090#1100
    TabOrder = 3
    OnClick = Button2Click
  end
  object ProgressBar1: TProgressBar
    Left = 16
    Top = 94
    Width = 297
    Height = 17
    TabOrder = 4
    Visible = False
  end
  object Button3: TButton
    Left = 335
    Top = 59
    Width = 75
    Height = 25
    Caption = '...'
    TabOrder = 5
    OnClick = Button3Click
  end
  object OpenDialog1: TOpenDialog
    Left = 560
    Top = 72
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 336
    Top = 144
  end
  object SaveDialog1: TSaveDialog
    Left = 400
    Top = 144
  end
end
