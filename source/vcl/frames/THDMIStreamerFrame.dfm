object HDMIStreamerFrame: THDMIStreamerFrame
  Left = 0
  Top = 0
  Width = 200
  Height = 247
  AutoSize = True
  TabOrder = 0
  object SettingsGB: TGroupBox
    Left = 0
    Top = 0
    Width = 200
    Height = 209
    Align = alTop
    Caption = 'Stream Settings'
    TabOrder = 0
    object BitrateE: TIntegerLabeledEdit
      Left = 16
      Top = 48
      Width = 65
      Height = 21
      EditLabel.Width = 63
      EditLabel.Height = 13
      EditLabel.Caption = 'Bitrate (kB/s)'
      TabOrder = 0
      Text = '25000'
      Value = 25000
    end
    object AppendTimeStampCB: TPropertyCheckBox
      Left = 32
      Top = 174
      Width = 121
      Height = 17
      Caption = 'Append TimeStamp'
      TabOrder = 1
    end
    object OutputFileFolderE: TSTDStringLabeledEdit
      Left = 16
      Top = 96
      Width = 169
      Height = 21
      EditLabel.Width = 86
      EditLabel.Height = 13
      EditLabel.Caption = 'Output File Folder'
      TabOrder = 2
      Text = 'P:\\Temp'
      Value = 'P:\\Temp'
    end
    object OutputFileNameE: TSTDStringLabeledEdit
      Left = 16
      Top = 147
      Width = 169
      Height = 21
      EditLabel.Width = 83
      EditLabel.Height = 13
      EditLabel.Caption = 'Output File Name'
      TabOrder = 3
      Text = 'Temp.ts'
      Value = 'Temp.ts'
    end
  end
  object StartRecordingBtn: TArrayBotButton
    Left = 0
    Top = 209
    Width = 200
    Height = 38
    Align = alTop
    Caption = 'Start Recording'
    TabOrder = 1
    OnClick = StartStreamerBtnClick
    SoundID = 'BUTTON_CLICK_4'
    ExplicitTop = 247
  end
  object CheckStatus: TTimer
    Enabled = False
    Interval = 150
    OnTimer = CheckStatusTimer
    Left = 40
    Top = 264
  end
end
