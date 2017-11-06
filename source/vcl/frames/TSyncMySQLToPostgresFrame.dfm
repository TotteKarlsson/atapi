object SyncMySQLToPostgresFrame: TSyncMySQLToPostgresFrame
  Left = 0
  Top = 0
  Width = 613
  Height = 448
  TabOrder = 0
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 613
    Height = 448
    Align = alClient
    TabOrder = 0
    object GroupBox2: TGroupBox
      Left = 1
      Top = 169
      Width = 611
      Height = 278
      Align = alClient
      Caption = 'Log'
      TabOrder = 0
      object SyncLogMemo: TMemo
        Left = 2
        Top = 15
        Width = 607
        Height = 261
        Align = alClient
        ScrollBars = ssBoth
        TabOrder = 0
        WordWrap = False
      end
    end
    object GroupBox1: TGroupBox
      Left = 1
      Top = 1
      Width = 611
      Height = 168
      Align = alTop
      Caption = 'Sync Parameters'
      TabOrder = 1
      object SyncButton: TButton
        Left = 304
        Top = 46
        Width = 257
        Height = 45
        Caption = 'Sync'
        TabOrder = 0
        OnClick = SyncButtonClick
      end
      object SyncScriptFile: TSTDStringLabeledEdit
        Left = 16
        Top = 58
        Width = 257
        Height = 21
        EditLabel.Width = 72
        EditLabel.Height = 13
        EditLabel.Caption = 'Sync Script File'
        TabOrder = 1
        Text = 'atdb_2_amazon_arraycam.s2p'
        Value = 'atdb_2_amazon_arraycam.s2p'
      end
    end
  end
end
