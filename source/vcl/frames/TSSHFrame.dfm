object SSHFrame: TSSHFrame
  Left = 0
  Top = 0
  Width = 227
  Height = 203
  AutoSize = True
  TabOrder = 0
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 227
    Height = 203
    Caption = 'Connection'
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 25
      Width = 54
      Height = 13
      Caption = 'SSH Server'
    end
    object Label2: TLabel
      Left = 152
      Top = 25
      Width = 42
      Height = 13
      Caption = 'SSH Port'
    end
    object Label3: TLabel
      Left = 16
      Top = 74
      Width = 51
      Height = 13
      Caption = 'User name'
    end
    object Label4: TLabel
      Left = 152
      Top = 74
      Width = 46
      Height = 13
      Caption = 'Password'
    end
    object edSSHHost: TEdit
      Left = 16
      Top = 44
      Width = 105
      Height = 21
      TabOrder = 0
      Text = 'atbigdawg'
    end
    object seSSHPort: TEdit
      Left = 152
      Top = 44
      Width = 65
      Height = 21
      TabOrder = 1
      Text = '22'
    end
    object edSSHUserName: TEdit
      Left = 16
      Top = 93
      Width = 105
      Height = 21
      TabOrder = 2
      Text = 'totte'
    end
    object edSSHPassword: TEdit
      Left = 152
      Top = 93
      Width = 65
      Height = 21
      PasswordChar = '*'
      TabOrder = 3
      Text = 'lacket47'
    end
    object ConnectBtn: TButton
      Left = 16
      Top = 148
      Width = 201
      Height = 49
      Caption = 'Connect'
      TabOrder = 4
      OnClick = ConnectBtnClick
    end
  end
  object ScFileStorage: TScFileStorage
    Password = 'lacket47'
    Left = 32
    Top = 96
  end
  object ScSSHShell1: TScSSHShell
    Client = ScSSHClient
    NonBlocking = True
    OnAsyncError = ScSSHShell1AsyncError
    Left = 160
    Top = 88
  end
  object ScSSHChannel: TScSSHChannel
    Client = ScSSHClient
    Left = 168
    Top = 16
  end
  object ScSSHClient: TScSSHClient
    HostName = 'atbigdawg'
    User = 'totte'
    Password = 'lacket47'
    KeyStorage = ScFileStorage
    AfterConnect = ScSSHClientAfterConnect
    BeforeConnect = ScSSHClientBeforeConnect
    AfterDisconnect = ScSSHClientAfterDisconnect
    OnServerKeyValidate = ScSSHClientServerKeyValidate
    Left = 48
    Top = 16
  end
end
