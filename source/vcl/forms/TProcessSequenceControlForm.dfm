object ProcessSequenceControlForm: TProcessSequenceControlForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Sequencer Control'
  ClientHeight = 327
  ClientWidth = 636
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object mSequenceNameLbl: TLabel
    Left = 40
    Top = 24
    Width = 172
    Height = 23
    Caption = 'mSequenceNameLbl'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object mProcessNameLbl: TLabel
    Left = 56
    Top = 101
    Width = 121
    Height = 23
    Caption = 'CurrProcName'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object mNextProcessNameLbl: TLabel
    Left = 256
    Top = 101
    Width = 123
    Height = 23
    Caption = 'NextProcName'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object mControlPanel: TPanel
    Left = 0
    Top = 140
    Width = 636
    Height = 187
    Align = alBottom
    TabOrder = 0
    DesignSize = (
      636
      187)
    object mStartResumeButton: TArrayBotButton
      Left = 30
      Top = 41
      Width = 170
      Height = 120
      Anchors = [akTop]
      Caption = 'Start'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = mStartResumeButtonClick
      SoundID = 'BUTTON_CLICK_4'
    end
    object mPauseBtn: TArrayBotButton
      Left = 241
      Top = 42
      Width = 170
      Height = 120
      Anchors = [akTop]
      Caption = 'Pause'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      SoundID = 'BUTTON_CLICK_4'
    end
    object mStopBtn: TArrayBotButton
      Left = 453
      Top = 42
      Width = 170
      Height = 120
      Anchors = [akTop]
      Caption = 'Exit'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = mStopBtnClick
      SoundID = 'BUTTON_CLICK_4'
    end
  end
  object mStatusTimer: TTimer
    Enabled = False
    Interval = 100
    OnTimer = mStatusTimerTimer
    Left = 528
    Top = 24
  end
end
