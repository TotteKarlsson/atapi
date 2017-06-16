object NavitarPreset: TNavitarPreset
  Left = 0
  Top = 0
  Width = 283
  Height = 66
  TabOrder = 0
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 283
    Height = 66
    Align = alClient
    Caption = 'Preset Name'
    TabOrder = 0
    ExplicitLeft = 56
    ExplicitTop = 35
    ExplicitWidth = 185
    ExplicitHeight = 105
    object ZoomPos: TIntegerLabeledEdit
      Left = 24
      Top = 36
      Width = 73
      Height = 21
      EditLabel.Width = 26
      EditLabel.Height = 13
      EditLabel.Caption = 'Zoom'
      TabOrder = 0
      Text = '0'
    end
    object FocusPos: TIntegerLabeledEdit
      Left = 120
      Top = 36
      Width = 73
      Height = 21
      EditLabel.Width = 28
      EditLabel.Height = 13
      EditLabel.Caption = 'Focus'
      TabOrder = 1
      Text = '0'
    end
    object GoButton: TButton
      Left = 224
      Top = 34
      Width = 48
      Height = 25
      Caption = '->'
      TabOrder = 2
      OnClick = GoButtonClick
    end
  end
end
