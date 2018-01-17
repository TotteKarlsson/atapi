object HDMIStreamerFrame: THDMIStreamerFrame
  Left = 0
  Top = 0
  Width = 200
  Height = 321
  AutoSize = True
  TabOrder = 0
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 200
    Height = 321
    Align = alClient
    Caption = 'Stream Settings'
    TabOrder = 0
    object BitrateE: TIntegerLabeledEdit
      Left = 16
      Top = 48
      Width = 121
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
    object StartStreamerBtn: TArrayBotButton
      Left = 16
      Top = 216
      Width = 121
      Height = 38
      Caption = 'Start Stream'
      TabOrder = 2
      OnClick = StartStreamerBtnClick
      SoundID = 'BUTTON_CLICK_4'
    end
    object FileOutputFolderE: TSTDStringLabeledEdit
      Left = 16
      Top = 96
      Width = 121
      Height = 21
      EditLabel.Width = 86
      EditLabel.Height = 13
      EditLabel.Caption = 'Output File Folder'
      TabOrder = 3
      Text = 'P:\\Temp'
      Value = 'P:\\Temp'
    end
    object OutputFileNameE: TSTDStringLabeledEdit
      Left = 16
      Top = 147
      Width = 121
      Height = 21
      EditLabel.Width = 83
      EditLabel.Height = 13
      EditLabel.Caption = 'Output File Name'
      TabOrder = 4
      Text = 'Temp.ts'
      Value = 'Temp.ts'
    end
  end
end
