object Editor: TEditor
  Left = 360
  Top = 114
  Width = 875
  Height = 661
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  Caption = #1057#1086#1079#1076#1072#1090#1100' '#1089#1074#1086#1081' '#1091#1088#1086#1074#1077#1085#1100
  Color = clBtnFace
  Constraints.MinHeight = 320
  Constraints.MinWidth = 640
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000080020000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    0000000000000000000000000000000000000000000000000000000000000000
    AAAAAAAAAAAAAAAAAAAAAAAA0000000AAAAAAAAAAAAAAAAAAAAAAAAAA000000A
    AAAAAAAAAAAAAAAAAAAAAAAAA000000AAAAAAAAAAAAAAAAAAAAAAAAA0000000A
    AAAA0000000000000000000000000000AAAA0000000000000000000000000000
    AAAA0000000000000000000000000000AAAAA000000000000000000000000000
    AAAAA0000099000000000000000000000AAAA000099990000000000000000000
    0AAAA0000999990000099000000000000AAAA000099999900099990000000000
    0AAAA0000099999999999900000000000AAAAA00000999999999990000000000
    00AAAA0000009999999990000000000000AAAA00000000999999000000000000
    00AAAAA0000009999999000000000000000AAAA0000099999999900000000000
    000AAAA0000099999999999000000000000AAAA0000999990999999900000000
    000AAAA0000999900099999900000000000AAAA0000099000009999000000000
    000AAAA0000000000000000000000000000AAAA0000000000000000000000000
    000AAAA0000000000000000000000000000AAAA0000000000000000000000000
    000AAAA00000000000000000000000000000AA00000000000000000000000000
    000000000000000000000000000000000000000000000000000000000000FFFF
    FFFFFFFFFFFFF000000FE0000007E0000007E000000FE0FFFFFFF0FFFFFFF0FF
    FFFFF07FFFFFF07CFFFFF8787FFFF8783E7FF8781C3FF87C003FF83E003FFC3F
    007FFC3FC0FFFC1F80FFFE1F007FFE1F001FFE1E080FFE1E1C0FFE1F3E1FFE1F
    FFFFFE1FFFFFFE1FFFFFFE1FFFFFFE1FFFFFFF3FFFFFFFFFFFFFFFFFFFFF}
  OldCreateOrder = False
  Position = poScreenCenter
  OnCloseQuery = FormCloseQuery
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object StrokCap: TLabel
    Left = 8
    Top = 8
    Width = 92
    Height = 17
    Caption = #1050#1086#1083'-'#1074#1086' '#1089#1090#1088#1086#1082': '
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object ShapeCap: TLabel
    Left = 152
    Top = 8
    Width = 108
    Height = 17
    Caption = #1050#1086#1083'-'#1074#1086' '#1087#1088#1077#1075#1088#1072#1076': '
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Strok: TEdit
    Left = 104
    Top = 8
    Width = 33
    Height = 21
    TabOrder = 0
    Text = '16'
  end
  object Ex: TButton
    Left = 304
    Top = 2
    Width = 81
    Height = 25
    Caption = #1042#1099#1081#1090#1080
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = ExClick
  end
  object Test: TButton
    Left = 389
    Top = 2
    Width = 84
    Height = 25
    Caption = #1047#1072#1090#1077#1089#1090#1080#1090#1100
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = TestClick
  end
  object Shapes: TEdit
    Left = 264
    Top = 8
    Width = 33
    Height = 21
    TabOrder = 3
    Text = '16'
  end
  object Edit: TMemo
    Left = 8
    Top = 32
    Width = 585
    Height = 433
    Lines.Strings = (
      '16'
      '16')
    TabOrder = 4
  end
  object Saver: TButton
    Left = 477
    Top = 2
    Width = 108
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
    OnClick = SaverClick
  end
  object Launch: TTimer
    Enabled = False
    Interval = 1
    OnTimer = LaunchTimer
    Left = 304
    Top = 184
  end
  object SaveSave: TSaveDialog
    FileName = 'New Level'
    Filter = 'XLabirint Files (*.xlab)|*.xlab'
    Title = #1057#1086#1079#1088#1072#1085#1080#1090#1100' '#1091#1088#1086#1074#1077#1085#1100' '#1082#1072#1082
    Left = 688
    Top = 96
  end
  object OpenSave: TOpenDialog
    FileName = '*.xlab'
    Filter = 'XLabirint Files (*.xlab)|*.xlab'
    Title = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1091#1088#1086#1074#1077#1085#1100
    Left = 696
    Top = 160
  end
end
