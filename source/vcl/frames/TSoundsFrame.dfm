object SoundsFrame: TSoundsFrame
  Left = 0
  Top = 0
  Width = 540
  Height = 313
  AutoSize = True
  TabOrder = 0
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 540
    Height = 313
    Caption = 'Available Sounds'
    TabOrder = 0
    object SoundsLB: TListBox
      Left = 2
      Top = 15
      Width = 239
      Height = 296
      Align = alLeft
      ItemHeight = 13
      TabOrder = 0
      OnClick = SoundsLBClick
    end
    object PlayBtn: TButton
      Left = 264
      Top = 160
      Width = 81
      Height = 41
      Caption = 'Play'
      TabOrder = 1
      OnClick = PlayBtnClick
    end
    object TrackBar1: TTrackBar
      Left = 264
      Top = 224
      Width = 150
      Height = 45
      Max = 0
      Min = -10000
      TabOrder = 2
      OnChange = TrackBar1Change
    end
    object StopBtn: TButton
      Left = 351
      Top = 160
      Width = 81
      Height = 41
      Caption = 'Stop'
      TabOrder = 3
      OnClick = PlayBtnClick
    end
    object RepeatSoundCB: TCheckBox
      Left = 438
      Top = 184
      Width = 65
      Height = 17
      Caption = 'Repeat'
      TabOrder = 4
    end
  end
end
