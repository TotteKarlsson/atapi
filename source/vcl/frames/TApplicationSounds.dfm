object ApplicationSounds: TApplicationSounds
  Left = 0
  Top = 0
  Width = 509
  Height = 321
  TabOrder = 0
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 509
    Height = 241
    Align = alTop
    Caption = 'Application Sounds'
    TabOrder = 0
    ExplicitWidth = 673
    object ApplicationSoundsLB: TListBox
      Left = 2
      Top = 15
      Width = 247
      Height = 224
      Align = alLeft
      ItemHeight = 13
      TabOrder = 0
      OnClick = ApplicationSoundsLBClick
    end
    object GroupBox2: TGroupBox
      Left = 249
      Top = 15
      Width = 258
      Height = 224
      Align = alClient
      Caption = 'Sound Properties'
      TabOrder = 1
      ExplicitLeft = 168
      ExplicitWidth = 502
      object EnabledCB: TCheckBox
        Left = 24
        Top = 143
        Width = 97
        Height = 17
        Caption = 'Enabled'
        Enabled = False
        TabOrder = 0
        OnClick = EnabledCBClick
      end
      object PlayBtn: TButton
        Left = 144
        Top = 105
        Width = 105
        Height = 32
        Caption = 'Play'
        TabOrder = 1
        OnClick = PlayBtnClick
      end
      object RepeatCB: TCheckBox
        Left = 24
        Top = 120
        Width = 97
        Height = 17
        Caption = 'RepeatCB'
        TabOrder = 2
        Visible = False
      end
      object SoundCB: TComboBox
        Left = 24
        Top = 32
        Width = 233
        Height = 21
        TabOrder = 3
        Text = 'SoundCB'
        OnCloseUp = SoundCBCloseUp
      end
      object VolumeTB: TTrackBar
        Left = 24
        Top = 73
        Width = 233
        Height = 26
        Max = 0
        Min = -10000
        TabOrder = 4
        TickStyle = tsNone
        OnChange = VolumeTBChange
      end
    end
  end
  object BindingsList1: TBindingsList
    Methods = <>
    OutputConverters = <>
    UseAppManager = True
    Left = 324
    Top = 181
  end
end
