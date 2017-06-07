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
    object ApplicationSoundsLB: TListBox
      Left = 2
      Top = 15
      Width = 239
      Height = 224
      Align = alLeft
      ItemHeight = 13
      TabOrder = 0
      OnClick = ApplicationSoundsLBClick
    end
    object SoundCB: TComboBox
      Left = 256
      Top = 40
      Width = 233
      Height = 21
      TabOrder = 1
      Text = 'SoundCB'
      OnCloseUp = SoundCBCloseUp
    end
    object VolumeTB: TTrackBar
      Left = 256
      Top = 81
      Width = 233
      Height = 26
      Max = 0
      Min = -10000
      TabOrder = 2
      TickStyle = tsNone
      OnChange = VolumeTBChange
    end
    object RepeatCB: TCheckBox
      Left = 256
      Top = 128
      Width = 97
      Height = 17
      Caption = 'RepeatCB'
      TabOrder = 3
      Visible = False
    end
    object PlayBtn: TButton
      Left = 376
      Top = 113
      Width = 105
      Height = 32
      Caption = 'Play'
      TabOrder = 4
      OnClick = PlayBtnClick
    end
  end
  object BindingsList1: TBindingsList
    Methods = <>
    OutputConverters = <>
    UseAppManager = True
    Left = 332
    Top = 181
  end
end
