object ApplicationSounds: TApplicationSounds
  Left = 0
  Top = 0
  Width = 673
  Height = 321
  TabOrder = 0
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 673
    Height = 241
    Align = alTop
    Caption = 'Application Sounds'
    TabOrder = 0
    object VolumeLbl: TIntLabel
      Left = 456
      Top = 81
      Width = 47
      Height = 13
      Caption = 'VolumeLbl'
      Value = -1
      TheFont.Charset = DEFAULT_CHARSET
      TheFont.Color = clWindowText
      TheFont.Height = -11
      TheFont.Name = 'Tahoma'
      TheFont.Style = []
    end
    object ApplicationSoundsCB: TListBox
      Left = 2
      Top = 15
      Width = 239
      Height = 224
      Align = alLeft
      ItemHeight = 13
      TabOrder = 0
      ExplicitHeight = 395
    end
    object SoundCB: TComboBox
      Left = 256
      Top = 40
      Width = 145
      Height = 21
      TabOrder = 1
      Text = 'SoundCB'
    end
    object VolumeTB: TTrackBar
      Left = 416
      Top = 40
      Width = 150
      Height = 26
      Max = 0
      Min = -10000
      TabOrder = 2
      TickStyle = tsNone
    end
    object RepeatCB: TCheckBox
      Left = 256
      Top = 80
      Width = 97
      Height = 17
      Caption = 'RepeatCB'
      TabOrder = 3
    end
  end
  object BindingsList1: TBindingsList
    Methods = <>
    OutputConverters = <>
    UseAppManager = True
    Left = 20
    Top = 5
  end
end
