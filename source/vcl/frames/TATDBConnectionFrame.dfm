object ATDBConnectionFrame: TATDBConnectionFrame
  Left = 0
  Top = 0
  Width = 286
  Height = 233
  TabOrder = 0
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 286
    Height = 233
    Caption = 'ATDB Connection'
    TabOrder = 0
    object mServerIPE: TSTDStringLabeledEdit
      Left = 16
      Top = 40
      Width = 121
      Height = 21
      EditLabel.Width = 45
      EditLabel.Height = 13
      EditLabel.Caption = 'Server IP'
      TabOrder = 1
      Text = '127.0.0.1'
      Value = '127.0.0.1'
    end
    object mDBUserE: TSTDStringLabeledEdit
      Left = 16
      Top = 89
      Width = 121
      Height = 21
      EditLabel.Width = 22
      EditLabel.Height = 13
      EditLabel.Caption = 'User'
      TabOrder = 2
      Text = 'atdb-client'
      Value = 'atdb-client'
    end
    object mPasswordE: TSTDStringLabeledEdit
      Left = 16
      Top = 137
      Width = 121
      Height = 21
      EditLabel.Width = 46
      EditLabel.Height = 13
      EditLabel.Caption = 'Password'
      TabOrder = 3
      Text = 'atdb123'
      Value = 'atdb123'
    end
    object mATDBServerBtnConnect: TArrayBotButton
      Left = 143
      Top = 89
      Width = 124
      Height = 64
      Caption = 'Connect/Disconnect'
      TabOrder = 0
      OnClick = mATDBServerBtnConnectClick
      SoundID = 'BUTTON_CLICK_4'
    end
    object mDatabaseE: TSTDStringLabeledEdit
      Left = 16
      Top = 185
      Width = 121
      Height = 21
      EditLabel.Width = 46
      EditLabel.Height = 13
      EditLabel.Caption = 'Database'
      TabOrder = 4
      Text = 'atdb'
      Value = 'atdb'
    end
  end
end
