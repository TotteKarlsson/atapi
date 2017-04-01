object SequenceInfoFrame: TSequenceInfoFrame
  Left = 0
  Top = 0
  Width = 441
  Height = 561
  AutoSize = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Tahoma'
  Font.Style = []
  ParentFont = False
  TabOrder = 0
  object GroupBox2: TGroupBox
    Left = 0
    Top = 0
    Width = 441
    Height = 561
    Align = alClient
    Caption = 'Master Processes'
    TabOrder = 0
    object Panel1: TPanel
      Left = 2
      Top = 25
      Width = 437
      Height = 405
      Align = alClient
      BevelEdges = []
      BevelOuter = bvNone
      TabOrder = 0
      object mProcessesLB: TListBox
        Left = 0
        Top = 0
        Width = 332
        Height = 405
        Align = alClient
        ItemHeight = 23
        TabOrder = 0
        OnClick = mProcessesLBClick
      end
      object Panel2: TPanel
        Left = 332
        Top = 0
        Width = 105
        Height = 405
        Align = alRight
        TabOrder = 1
        object mDeleteMoveBtn: TArrayBotButton
          Left = 1
          Top = 1
          Width = 103
          Height = 45
          Action = RemoveProcessA
          Align = alTop
          Caption = 'X'
          ParentDoubleBuffered = True
          TabOrder = 0
          SoundID = 'BUTTON_CLICK_4'
        end
        object mMoveSequenceDownBtn: TArrayBotButton
          Left = 1
          Top = 91
          Width = 103
          Height = 45
          Align = alTop
          Caption = #9660
          ParentDoubleBuffered = True
          TabOrder = 1
          OnClick = mMoveSequenceDownBtnClick
          SoundID = 'BUTTON_CLICK_4'
        end
        object mMoveSequenceUpBtn: TArrayBotButton
          Left = 1
          Top = 46
          Width = 103
          Height = 45
          Align = alTop
          Caption = #9650
          ParentDoubleBuffered = True
          TabOrder = 2
          OnClick = mMoveSequenceUpBtnClick
          SoundID = 'BUTTON_CLICK_4'
        end
        object mRenameBtn: TArrayBotButton
          Left = 1
          Top = 136
          Width = 103
          Height = 50
          Align = alTop
          Caption = 'Rename'
          TabOrder = 3
          OnClick = mRenameBtnClick
          SoundID = 'BUTTON_CLICK_4'
        end
      end
    end
    object Panel3: TPanel
      Left = 2
      Top = 430
      Width = 437
      Height = 129
      Align = alBottom
      TabOrder = 1
      object mAddMoveBtn: TArrayBotButton
        Left = 1
        Top = 1
        Width = 435
        Height = 60
        Action = AddCombinedMoveA
        Align = alTop
        Caption = 'New Process'
        ParentDoubleBuffered = True
        TabOrder = 0
        SoundID = 'BUTTON_CLICK_4'
      end
      object mUpdatePositionsBtn: TArrayBotButton
        Left = 1
        Top = 61
        Width = 435
        Height = 67
        Align = alClient
        ParentDoubleBuffered = True
        TabOrder = 1
        OnClick = mUpdatePositionsBtnClick
        SoundID = 'BUTTON_CLICK_4'
      end
    end
  end
  object mSequenceAL: TActionList
    Left = 208
    Top = 16
    object RemoveProcessA: TAction
      Caption = 'X'
      OnExecute = RemoveProcessAExecute
    end
    object AddCombinedMoveA: TAction
      Caption = 'New Master Process'
      OnExecute = AddCombinedMoveAExecute
    end
  end
end
