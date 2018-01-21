object Form_Cab: TForm_Cab
  Left = 148
  Top = 11
  Width = 1080
  Height = 696
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1064
    Height = 65
    Align = alTop
    TabOrder = 0
    object Label1: TLabel
      Left = 136
      Top = 16
      Width = 6
      Height = 19
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Comic Sans MS'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Button1: TButton
      Left = 912
      Top = 8
      Width = 145
      Height = 33
      Caption = #1054#1090#1095#1077#1090' '#1087#1086' '#1082#1072#1073#1080#1085#1077#1090#1072#1084
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Comic Sans MS'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      Visible = False
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 272
      Top = 8
      Width = 121
      Height = 33
      Caption = #1043#1088#1072#1092#1080#1082' '#1088#1072#1073#1086#1090#1099
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Comic Sans MS'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 408
      Top = 8
      Width = 121
      Height = 33
      Caption = #1042#1099#1073#1088#1072#1090#1100' '#1074#1088#1072#1095#1072
      Enabled = False
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Comic Sans MS'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      Visible = False
      OnClick = Button3Click
    end
    object BitBtn1: TBitBtn
      Left = 592
      Top = 8
      Width = 121
      Height = 33
      Caption = #1054#1073#1085#1086#1074#1080#1090#1100
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Comic Sans MS'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      OnClick = DateEdit1Change
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000120B0000120B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00300130000031
        00333773F77777FF7733331000909000133333377737F777FF33330098F0F890
        0333337733F733F77F33370980FFF08907333373373F373373F33099FF0FFFF9
        903337F3F373F33FF7F33090FFF0FF00903337F73337F37737F33099FFF0FFF9
        9033373F33F7F3F33733370980F0F0890733337FF737F7337F33330098F0F890
        03333F77FF3733377FFF000009999900000377777FFFFF77777F088700000008
        77037F3377777773337F088887707888870373F3337773F33373307880707088
        7033373FF737F73FF733337003303300733333777337FF777333333333000333
        3333333333777333333333333333333333333333333333333333}
      NumGlyphs = 2
    end
    object ProgressBar1: TProgressBar
      Left = 8
      Top = 45
      Width = 385
      Height = 17
      Min = 0
      Max = 160
      TabOrder = 4
    end
    object DateEdit1: TDateEdit
      Left = 8
      Top = 16
      Width = 121
      Height = 27
      DefaultToday = True
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Comic Sans MS'
      Font.Style = [fsBold]
      NumGlyphs = 2
      ParentFont = False
      CalendarStyle = csPopup
      TabOrder = 5
      OnChange = DateEdit1Change
    end
  end
  object Planner1: TPlanner
    Left = 0
    Top = 65
    Width = 1064
    Height = 592
    Align = alClient
    AllowClipboardShortCuts = True
    AttachementGlyph.Data = {
      F6000000424DF600000000000000760000002800000010000000100000000100
      0400000000008000000000000000000000001000000000000000000000000000
      8000008000000080800080000000800080008080000080808000C0C0C0000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
      8888888888700078888888888708880788888888808808808888888880808080
      8888888880808080888888888080808088888888808080808888888880808080
      8888888880808080888888888080808088888888808080808888888888808080
      8888888888808880888888888888000888888888888888888888}
    Caption.Title = #1047#1072#1075#1088#1091#1078#1077#1085#1085#1086#1089#1090#1100' '#1082#1072#1073#1080#1085#1077#1090#1086#1074
    Caption.Font.Charset = RUSSIAN_CHARSET
    Caption.Font.Color = clBlack
    Caption.Font.Height = -15
    Caption.Font.Name = 'Comic Sans MS'
    Caption.Font.Style = [fsBold]
    Caption.Background = 16575452
    Caption.BackgroundTo = 16571329
    DayNames.Strings = (
      #1042#1086#1089#1082#1088#1077#1089#1077#1085#1100#1077
      #1055#1086#1085#1077#1076#1077#1083#1100#1085#1080#1082
      #1042#1090#1086#1088#1085#1080#1082
      #1057#1088#1077#1076#1072
      #1063#1077#1090#1074#1077#1088#1075
      #1055#1103#1090#1085#1080#1094#1072
      #1057#1091#1073#1073#1086#1090#1072)
    DefaultItem.CaptionBkg = 16109705
    DefaultItem.CaptionBkgTo = 16109705
    DefaultItem.CaptionFont.Charset = DEFAULT_CHARSET
    DefaultItem.CaptionFont.Color = clWindowText
    DefaultItem.CaptionFont.Height = -11
    DefaultItem.CaptionFont.Name = 'MS Sans Serif'
    DefaultItem.CaptionFont.Style = []
    DefaultItem.Color = clRed
    DefaultItem.ColorTo = clWhite
    DefaultItem.Cursor = -1
    DefaultItem.FixedPos = True
    DefaultItem.FixedSize = True
    DefaultItem.Font.Charset = DEFAULT_CHARSET
    DefaultItem.Font.Color = clWindowText
    DefaultItem.Font.Height = -11
    DefaultItem.Font.Name = 'MS Sans Serif'
    DefaultItem.Font.Style = []
    DefaultItem.ItemBegin = 16
    DefaultItem.ItemEnd = 17
    DefaultItem.ItemPos = 0
    DefaultItem.Name = 'PlannerItem0'
    DefaultItem.ReadOnly = True
    DefaultItem.Shape = psRounded
    DefaultItem.SelectColor = 16571329
    DefaultItem.SelectColorTo = 16575452
    DefaultItem.Shadow = True
    DefaultItem.TrackColor = 16571329
    DefaultItem.TrackSelectColor = 11369558
    DeleteGlyph.Data = {
      36050000424D3605000000000000360400002800000010000000100000000100
      0800000000000001000000000000000000000001000000000000000000000000
      80000080000000808000800000008000800080800000C0C0C000C0DCC000F0CA
      A6000020400000206000002080000020A0000020C0000020E000004000000040
      20000040400000406000004080000040A0000040C0000040E000006000000060
      20000060400000606000006080000060A0000060C0000060E000008000000080
      20000080400000806000008080000080A0000080C0000080E00000A0000000A0
      200000A0400000A0600000A0800000A0A00000A0C00000A0E00000C0000000C0
      200000C0400000C0600000C0800000C0A00000C0C00000C0E00000E0000000E0
      200000E0400000E0600000E0800000E0A00000E0C00000E0E000400000004000
      20004000400040006000400080004000A0004000C0004000E000402000004020
      20004020400040206000402080004020A0004020C0004020E000404000004040
      20004040400040406000404080004040A0004040C0004040E000406000004060
      20004060400040606000406080004060A0004060C0004060E000408000004080
      20004080400040806000408080004080A0004080C0004080E00040A0000040A0
      200040A0400040A0600040A0800040A0A00040A0C00040A0E00040C0000040C0
      200040C0400040C0600040C0800040C0A00040C0C00040C0E00040E0000040E0
      200040E0400040E0600040E0800040E0A00040E0C00040E0E000800000008000
      20008000400080006000800080008000A0008000C0008000E000802000008020
      20008020400080206000802080008020A0008020C0008020E000804000008040
      20008040400080406000804080008040A0008040C0008040E000806000008060
      20008060400080606000806080008060A0008060C0008060E000808000008080
      20008080400080806000808080008080A0008080C0008080E00080A0000080A0
      200080A0400080A0600080A0800080A0A00080A0C00080A0E00080C0000080C0
      200080C0400080C0600080C0800080C0A00080C0C00080C0E00080E0000080E0
      200080E0400080E0600080E0800080E0A00080E0C00080E0E000C0000000C000
      2000C0004000C0006000C0008000C000A000C000C000C000E000C0200000C020
      2000C0204000C0206000C0208000C020A000C020C000C020E000C0400000C040
      2000C0404000C0406000C0408000C040A000C040C000C040E000C0600000C060
      2000C0604000C0606000C0608000C060A000C060C000C060E000C0800000C080
      2000C0804000C0806000C0808000C080A000C080C000C080E000C0A00000C0A0
      2000C0A04000C0A06000C0A08000C0A0A000C0A0C000C0A0E000C0C00000C0C0
      2000C0C04000C0C06000C0C08000C0C0A000F0FBFF00A4A0A000808080000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00D9ED07070707
      0707070707070707ECD9EC5E5E5E5E5E5E5E5E5E5E5E5E5E5DED070D0E161616
      161616160E0E0E0E5E07070D161656561616161616160E0E5E07070D16AF075E
      56561657B7EF0E0E5E07070D56AFF6075F565FAFF6AF160E5E07070D565EAFF6
      075FEFF6AF17160E5E07070D5E5E5EAFF607F6AF161616165E07070D5E5E5E5E
      EFF60756161616165E07070D5E5E5FEFF6EFF6075E1616165E07070D5F5F07F6
      EF5EAFF6075616165E07070D6707F6075E5656AFF60716165E07070DA7AF075F
      5E5E5E5EAFAF56165E07070DA7A7675F5F5E5E5E5E5E56165E07EDAF0D0D0D0D
      0D0D0D0D0D0D0D0D5EECD9ED070707070707070707070707EDD1}
    Display.ActiveStart = 88
    Display.ActiveEnd = 0
    Display.DisplayStart = 32
    Display.DisplayEnd = 84
    Display.DisplayScale = 50
    Display.DisplayUnit = 15
    Display.ColorActive = 16575452
    Display.ColorNonActive = clWhite
    Display.ColorCurrent = clSilver
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Footer.Captions.Strings = (
      ''
      ''
      ''
      ''
      ''
      ''
      ''
      ''
      ''
      ''
      '')
    Footer.CompletionFormat = '%d%%'
    Footer.Color = 16645114
    Footer.ColorTo = 16643051
    Footer.Completion.Font.Charset = DEFAULT_CHARSET
    Footer.Completion.Font.Color = clWindowText
    Footer.Completion.Font.Height = -11
    Footer.Completion.Font.Name = 'Arial'
    Footer.Completion.Font.Style = []
    Footer.Font.Charset = DEFAULT_CHARSET
    Footer.Font.Color = clWindowText
    Footer.Font.Height = -11
    Footer.Font.Name = 'MS Sans Serif'
    Footer.Font.Style = []
    GridLeftCol = 1
    GridLineColor = clGray
    GridTopRow = 0
    Header.ActiveColor = 16575452
    Header.ActiveColorTo = 16571329
    Header.AllowResize = True
    Header.AllowPositionResize = True
    Header.AutoSize = True
    Header.AutoSizeGroupCaption = True
    Header.Captions.Strings = (
      '1'
      '2'
      ''
      ''
      ''
      ''
      ''
      ''
      ''
      ''
      ''
      '')
    Header.Color = 16645114
    Header.ColorTo = 16643051
    Header.CustomGroups = <>
    Header.DragDrop = True
    Header.Height = 34
    Header.Font.Charset = RUSSIAN_CHARSET
    Header.Font.Color = clBlack
    Header.Font.Height = -13
    Header.Font.Name = 'Comic Sans MS'
    Header.Font.Style = []
    Header.GroupHeight = 0
    Header.GroupFont.Charset = DEFAULT_CHARSET
    Header.GroupFont.Color = clWindowText
    Header.GroupFont.Height = -11
    Header.GroupFont.Name = 'MS Sans Serif'
    Header.GroupFont.Style = []
    Header.ItemHeight = 40
    Header.ReadOnly = False
    Header.ResizeAll = False
    HintColor = clLime
    HintPause = 2500
    HTMLOptions.CellFontStyle = []
    HTMLOptions.HeaderFontStyle = []
    HTMLOptions.SidebarFontStyle = []
    InActiveDays.Sun = False
    InActiveDays.Mon = True
    InActiveDays.Tue = True
    InActiveDays.Wed = True
    InActiveDays.Thu = True
    InActiveDays.Fri = True
    Items = <
      item
        AllowOverlap = False
        CaptionBkg = clBlue
        CaptionBkgTo = clWhite
        CaptionBkgDirection = gdVertical
        CaptionFont.Charset = DEFAULT_CHARSET
        CaptionFont.Color = clWindowText
        CaptionFont.Height = -11
        CaptionFont.Name = 'MS Sans Serif'
        CaptionFont.Style = []
        CaptionType = ctText
        Color = clBlue
        ColorTo = clWhite
        Cursor = -1
        FixedPos = True
        FixedSize = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        Hint = 'yhgfhgfj'
        HintIndicator = True
        ItemBegin = 8
        ItemEnd = 9
        ItemPos = 2
        Name = 'PlannerItem0'
        ReadOnly = True
        Shape = psRounded
        ShowSelection = False
        SelectColor = clGreen
        SelectColorTo = clPurple
        Shadow = False
        TrackColor = 16571329
        TrackSelectColor = 11369558
        TrackVisible = False
      end>
    Mode.Month = 10
    Mode.PeriodStartDay = 25
    Mode.PeriodStartMonth = 10
    Mode.PeriodStartYear = 2014
    Mode.PeriodEndDay = 2
    Mode.PeriodEndMonth = 11
    Mode.PeriodEndYear = 2014
    Mode.TimeLineStart = 41937
    Mode.TimeLineNVUBegin = 0
    Mode.TimeLineNVUEnd = 0
    Mode.Year = 2014
    Mode.Day = 25
    SelectionAlways = False
    Sidebar.Background = 16645114
    Sidebar.BackgroundTo = 16643051
    Sidebar.Font.Charset = DEFAULT_CHARSET
    Sidebar.Font.Color = clBlack
    Sidebar.Font.Height = -12
    Sidebar.Font.Name = 'Arial'
    Sidebar.Font.Style = [fsBold]
    Sidebar.HourFontRatio = 1
    Sidebar.Occupied = clWhite
    Sidebar.OccupiedTo = clWhite
    Sidebar.Width = 45
    Positions = 4
    PositionProps = <>
    PositionWidth = 160
    PrintOptions.LineWidth = 0
    PrintOptions.FooterFont.Charset = DEFAULT_CHARSET
    PrintOptions.FooterFont.Color = clWindowText
    PrintOptions.FooterFont.Height = -11
    PrintOptions.FooterFont.Name = 'MS Sans Serif'
    PrintOptions.FooterFont.Style = []
    PrintOptions.HeaderFont.Charset = DEFAULT_CHARSET
    PrintOptions.HeaderFont.Color = clWindowText
    PrintOptions.HeaderFont.Height = -11
    PrintOptions.HeaderFont.Name = 'MS Sans Serif'
    PrintOptions.HeaderFont.Style = []
    ScrollSmooth = True
    ScrollSynch = True
    ScrollBarStyle.Color = clGreen
    ScrollBarStyle.Width = 20
    SelectColor = clWhite
    SelectRange = False
    ShowDesignHelper = False
    SyncPlanner.ScrollVertical = True
    SyncPlanner.ScrollHorizontal = True
    TrackColor = 16571329
    URLGlyph.Data = {
      F6000000424DF600000000000000760000002800000010000000100000000100
      0400000000008000000000000000000000001000000000000000000000000000
      8000008000000080800080000000800080008080000080808000C0C0C0000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888880000800
      0088888808F8F0F8F80888808000000000808880F070888070F0888080000000
      0080880408F8F0F8F80880CCC0000400008874CCC2222C4788887CCCC22226C0
      88887CC822222CC088887C822224642088887C888422C220888877CF8CCCC227
      888887F8F8222208888888776888208888888887777778888888}
    Version = '3.0.0.1'
    WheelAction = pwaScroll
    OnItemRightClick = Planner1ItemRightClick
    OnItemDblClick = Planner1ItemDblClick
    OnItemDelete = Planner1ItemDelete
    OnPlannerNext = Planner1PlannerNext
    OnPlannerPrev = Planner1PlannerPrev
  end
  object Button4: TButton
    Left = 776
    Top = 8
    Width = 121
    Height = 33
    Caption = #1054#1090#1095#1077#1090' '#1087#1086' '#1079#1072#1087#1080#1089#1080
    Enabled = False
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Comic Sans MS'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    Visible = False
    OnClick = Button4Click
  end
  object MTemp: TADOQuery
    Connection = Data1.Med
    Parameters = <>
    Left = 784
    Top = 200
  end
  object MTemp1: TADOQuery
    Connection = Data1.Med
    Parameters = <>
    Left = 872
    Top = 176
  end
  object MTemp2: TADOQuery
    Connection = Data1.Med
    Parameters = <>
    Left = 840
    Top = 192
  end
  object MTemp3: TADOQuery
    Connection = Data1.Med
    Parameters = <>
    Left = 888
    Top = 200
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 600000
    OnTimer = Timer1Timer
    Left = 272
    Top = 192
  end
end
