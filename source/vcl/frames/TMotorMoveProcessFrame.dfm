object MotorMoveProcessFrame: TMotorMoveProcessFrame
  Left = 0
  Top = 0
  Width = 803
  Height = 766
  Align = alClient
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Tahoma'
  Font.Style = []
  ParentFont = False
  TabOrder = 0
  ExplicitWidth = 451
  ExplicitHeight = 304
  object mMainGB: TGroupBox
    Left = 0
    Top = 0
    Width = 803
    Height = 465
    Align = alTop
    Caption = 'Action Properties'
    Padding.Left = 15
    Padding.Right = 15
    TabOrder = 1
    object Panel2: TPanel
      Left = 17
      Top = 296
      Width = 769
      Height = 167
      Align = alBottom
      BevelOuter = bvNone
      TabOrder = 0
      ExplicitTop = 200
      object Label1: TLabel
        Left = 16
        Top = 15
        Width = 48
        Height = 23
        Caption = 'Motor'
      end
      object mAccE: TFloatLabeledEdit
        Left = 240
        Top = 121
        Width = 105
        Height = 31
        EditLabel.Width = 101
        EditLabel.Height = 23
        EditLabel.Caption = 'Acceleration'
        TabOrder = 3
        Text = '0.0'
        OnKeyDown = mMovePosEKeyDown
      end
      object mMaxVelE: TFloatLabeledEdit
        Left = 128
        Top = 121
        Width = 105
        Height = 31
        EditLabel.Width = 63
        EditLabel.Height = 23
        EditLabel.Caption = 'Velocity'
        TabOrder = 2
        Text = '0.0'
        OnKeyDown = mMovePosEKeyDown
      end
      object mMovePosE: TFloatLabeledEdit
        Left = 16
        Top = 121
        Width = 105
        Height = 31
        EditLabel.Width = 108
        EditLabel.Height = 23
        EditLabel.Caption = 'Final Position'
        TabOrder = 1
        Text = '0.0'
        OnKeyDown = mMovePosEKeyDown
      end
      object MotorsCB: TComboBox
        Left = 16
        Top = 44
        Width = 281
        Height = 31
        Style = csDropDownList
        TabOrder = 0
        OnChange = MotorsCBChange
      end
    end
    object Panel1: TPanel
      Left = 17
      Top = 25
      Width = 769
      Height = 271
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 1
      ExplicitHeight = 151
      object mActionInfo: TLabel
        Left = 0
        Top = 0
        Width = 233
        Height = 271
        Align = alLeft
        AutoSize = False
        Caption = 
          'This move will move the Z motor to a good position for cover sli' +
          'p extraction. As Z gets above 200 mm, the x motor is triggered t' +
          'o move to a convenient position.'
        Layout = tlCenter
        WordWrap = True
        OnClick = mActionInfoClick
        ExplicitHeight = 151
      end
      object mAddTriggerBtn: TArrayBotButton
        Left = 233
        Top = 0
        Width = 536
        Height = 271
        Align = alClient
        Caption = 'Add Child Action'
        Enabled = False
        ParentDoubleBuffered = True
        TabOrder = 0
        OnClick = AddTriggerBClick
        SoundID = 'BUTTON_CLICK_4'
        ExplicitLeft = 240
        ExplicitWidth = 177
        ExplicitHeight = 151
      end
    end
  end
  object mTriggerPanel: TPanel
    Left = 0
    Top = 465
    Width = 803
    Height = 301
    Align = alClient
    TabOrder = 0
    ExplicitTop = 440
    ExplicitHeight = 326
    object GroupBox1: TGroupBox
      Left = 377
      Top = 32
      Width = 200
      Height = 125
      Caption = 'Triggers'
      TabOrder = 0
      Visible = False
      object mTriggersLB: TListBox
        Left = 2
        Top = 25
        Width = 196
        Height = 98
        Align = alClient
        ItemHeight = 23
        TabOrder = 0
        OnClick = TriggersLBClick
        ExplicitLeft = -6
      end
    end
  end
end
