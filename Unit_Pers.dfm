object Form_Pers: TForm_Pers
  Left = 380
  Top = 128
  BorderStyle = bsDialog
  Caption = #1042#1099#1073#1086#1088' '#1074#1088#1072#1095#1072
  ClientHeight = 489
  ClientWidth = 345
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Comic Sans MS'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 18
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 345
    Height = 489
    Align = alClient
    TabOrder = 0
    object DBGrid1: TDBGrid
      Left = 1
      Top = 1
      Width = 250
      Height = 487
      Align = alLeft
      DataSource = Data1.dsPerson
      Font.Charset = RUSSIAN_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Comic Sans MS'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      TitleFont.Charset = RUSSIAN_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -13
      TitleFont.Name = 'Comic Sans MS'
      TitleFont.Style = []
      OnDblClick = DBGrid1DblClick
      Columns = <
        item
          Expanded = False
          FieldName = 'Name'
          Title.Caption = #1060#1040#1052#1048#1051#1048#1071
          Title.Font.Charset = RUSSIAN_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -12
          Title.Font.Name = 'Comic Sans MS'
          Title.Font.Style = [fsBold]
          Width = 189
          Visible = True
        end>
    end
  end
end
