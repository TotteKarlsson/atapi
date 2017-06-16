object PresetsFrame: TPresetsFrame
  Left = 0
  Top = 0
  Width = 573
  Height = 491
  TabOrder = 0
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 573
    Height = 491
    Align = alClient
    Caption = 'Presets'
    TabOrder = 0
    ExplicitLeft = 48
    ExplicitTop = 112
    ExplicitWidth = 361
    ExplicitHeight = 217
    inline TNavitarPreset1: TNavitarPreset
      Left = 2
      Top = 81
      Width = 569
      Height = 66
      Align = alTop
      TabOrder = 0
      ExplicitLeft = 79
      ExplicitTop = 76
      inherited GroupBox1: TGroupBox
        Width = 569
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 283
        ExplicitHeight = 66
        inherited ZoomPos: TIntegerLabeledEdit
          EditLabel.ExplicitLeft = 0
          EditLabel.ExplicitTop = -16
          EditLabel.ExplicitWidth = 43
        end
        inherited FocusPos: TIntegerLabeledEdit
          EditLabel.ExplicitLeft = 0
          EditLabel.ExplicitTop = -16
          EditLabel.ExplicitWidth = 45
        end
      end
    end
    inline NavitarPreset1: TNavitarPreset
      Left = 2
      Top = 15
      Width = 569
      Height = 66
      Align = alTop
      TabOrder = 1
      ExplicitLeft = 158
      ExplicitTop = 169
      inherited GroupBox1: TGroupBox
        Width = 569
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 283
        ExplicitHeight = 66
        inherited ZoomPos: TIntegerLabeledEdit
          EditLabel.ExplicitLeft = 0
          EditLabel.ExplicitTop = -16
          EditLabel.ExplicitWidth = 43
        end
        inherited FocusPos: TIntegerLabeledEdit
          EditLabel.ExplicitLeft = 0
          EditLabel.ExplicitTop = -16
          EditLabel.ExplicitWidth = 45
        end
      end
    end
    inline NavitarPreset2: TNavitarPreset
      Left = 2
      Top = 147
      Width = 569
      Height = 66
      Align = alTop
      TabOrder = 2
      ExplicitLeft = 205
      ExplicitTop = 292
      inherited GroupBox1: TGroupBox
        Width = 569
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 283
        ExplicitHeight = 66
        inherited ZoomPos: TIntegerLabeledEdit
          EditLabel.ExplicitLeft = 0
          EditLabel.ExplicitTop = -16
          EditLabel.ExplicitWidth = 43
        end
        inherited FocusPos: TIntegerLabeledEdit
          EditLabel.ExplicitLeft = 0
          EditLabel.ExplicitTop = -16
          EditLabel.ExplicitWidth = 45
        end
      end
    end
  end
end
