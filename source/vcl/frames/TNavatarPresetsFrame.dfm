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
    inline TNavitarPreset1: TNavitarPreset
      Left = 2
      Top = 81
      Width = 569
      Height = 66
      Align = alTop
      TabOrder = 0
      ExplicitLeft = 2
      ExplicitTop = 81
      ExplicitWidth = 569
      inherited GroupBox1: TGroupBox
        Width = 569
        ExplicitWidth = 569
      end
    end
    inline NavitarPreset1: TNavitarPreset
      Left = 2
      Top = 15
      Width = 569
      Height = 66
      Align = alTop
      TabOrder = 1
      ExplicitLeft = 2
      ExplicitTop = 15
      ExplicitWidth = 569
      inherited GroupBox1: TGroupBox
        Width = 569
        ExplicitWidth = 569
      end
    end
    inline NavitarPreset2: TNavitarPreset
      Left = 2
      Top = 147
      Width = 569
      Height = 66
      Align = alTop
      TabOrder = 2
      ExplicitLeft = 2
      ExplicitTop = 147
      ExplicitWidth = 569
      inherited GroupBox1: TGroupBox
        Width = 569
        ExplicitWidth = 569
      end
    end
  end
end
