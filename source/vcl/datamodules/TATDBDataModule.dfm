object atdbDM: TatdbDM
  OldCreateOrder = False
  Height = 765
  Width = 887
  object SQLConnection1: TSQLConnection
    DriverName = 'MySQL'
    LoginPrompt = False
    Params.Strings = (
      'DriverUnit=Data.DBXMySQL'
      
        'DriverPackageLoader=TDBXDynalinkDriverLoader,DbxCommonDriver170.' +
        'bpl'
      
        'DriverAssemblyLoader=Borland.Data.TDBXDynalinkDriverLoader,Borla' +
        'nd.Data.DbxCommonDriver,Version=17.0.0.0,Culture=neutral,PublicK' +
        'eyToken=91d62ebb5b0d1b1b'
      
        'MetaDataPackageLoader=TDBXMySqlMetaDataCommandFactory,DbxMySQLDr' +
        'iver170.bpl'
      
        'MetaDataAssemblyLoader=Borland.Data.TDBXMySqlMetaDataCommandFact' +
        'ory,Borland.Data.DbxMySQLDriver,Version=17.0.0.0,Culture=neutral' +
        ',PublicKeyToken=91d62ebb5b0d1b1b'
      'GetDriverFunc=getSQLDriverMYSQL'
      'LibraryName=dbxmys.dll'
      'LibraryNameOsx=libsqlmys.dylib'
      'VendorLib=LIBMYSQL.dll'
      'VendorLibWin64=libmysql.dll'
      'VendorLibOsx=libmysqlclient.dylib'
      'HostName=localhost'
      'Database=atdb'
      'User_Name=atdb_client'
      'Password=atdb123'
      'MaxBlobSize=-1'
      'LocaleCode=0000'
      'Compressed=False'
      'Encrypted=False'
      'BlobSize=-1'
      'ErrorResourceFile=')
    AfterConnect = SQLConnection1AfterConnect
    BeforeConnect = SQLConnection1BeforeConnect
    Connected = True
    Left = 40
    Top = 24
  end
  object blocksDataSource: TDataSource
    DataSet = blocksCDS
    Left = 336
    Top = 240
  end
  object blocksCDS: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'blocksProvider'
    BeforePost = cdsBeforePost
    AfterPost = cdsAfterPost
    AfterDelete = cdsAfterDelete
    AfterScroll = cdsAfterScroll
    AfterRefresh = cdsAfterRefresh
    OnCalcFields = blocksCDSCalcFields
    Left = 240
    Top = 240
    object blocksCDSid: TIntegerField
      AutoGenerateValue = arAutoInc
      FieldName = 'id'
    end
    object blocksCDScreated: TSQLTimeStampField
      AutoGenerateValue = arDefault
      DisplayLabel = 'Created On'
      FieldName = 'created'
      OnGetText = TimeStampGetText
    end
    object blocksCDScreated_by: TIntegerField
      FieldName = 'created_by'
      Required = True
    end
    object blocksCDSmodified: TSQLTimeStampField
      FieldName = 'modified'
    end
    object blocksCDSlabel: TStringField
      DisplayLabel = 'Label'
      FieldName = 'label'
      Size = 255
    end
    object blocksCDSprocess_id: TIntegerField
      Alignment = taLeftJustify
      DisplayLabel = 'Process ID'
      FieldName = 'process_id'
    end
    object blocksCDSstatus: TSmallintField
      FieldName = 'status'
      Required = True
    end
    object blocksCDSLprocess_id: TIntegerField
      DisplayLabel = 'Process ID'
      FieldKind = fkLookup
      FieldName = 'Lprocess_id'
      LookupDataSet = processIDDS
      LookupKeyFields = 'process_id'
      LookupResultField = 'process_id'
      KeyFields = 'process_id'
      Lookup = True
    end
    object blocksCDSLBlockStatus: TStringField
      DisplayLabel = 'Status'
      FieldKind = fkLookup
      FieldName = 'LBlockStatus'
      LookupDataSet = blockstatusDS
      LookupKeyFields = 'id'
      LookupResultField = 'status'
      KeyFields = 'status'
      Size = 255
      Lookup = True
    end
    object blocksCDSserial: TSmallintField
      Alignment = taLeftJustify
      DisplayLabel = 'Serial'
      FieldName = 'serial'
      Required = True
    end
    object blocksCDSCBlockLabel: TStringField
      FieldKind = fkCalculated
      FieldName = 'Cblock_label'
      Size = 50
      Calculated = True
    end
    object blocksCDSdate_embedded: TDateField
      FieldName = 'date_embedded'
    end
    object blocksCDSpreprocess_treatment_protocol: TSmallintField
      FieldName = 'preprocess_treatment_protocol'
    end
    object blocksCDSfixative_protocol: TSmallintField
      FieldName = 'fixative_protocol'
    end
    object blocksCDSfixation_protocol: TSmallintField
      FieldName = 'fixation_protocol'
    end
    object blocksCDSpostfix_protocol: TSmallintField
      FieldName = 'postfix_protocol'
    end
    object blocksCDScryoprotection_protocol: TSmallintField
      FieldName = 'cryoprotection_protocol'
    end
    object blocksCDSfreezing_protocol: TSmallintField
      FieldName = 'freezing_protocol'
    end
    object blocksCDSsubstitution_protocol: TSmallintField
      FieldName = 'substitution_protocol'
    end
    object blocksCDSinfiltration_protocol: TSmallintField
      FieldName = 'infiltration_protocol'
    end
    object blocksCDSembedding_protocol: TSmallintField
      FieldName = 'embedding_protocol'
    end
    object blocksCDSLPreprocessTreatmentProtocol: TStringField
      FieldKind = fkLookup
      FieldName = 'LPreprocessTreatmentProtocol'
      LookupDataSet = preprocesstreatmentDS
      LookupKeyFields = 'id'
      LookupResultField = 'protocol'
      KeyFields = 'preprocess_treatment_protocol'
      Lookup = True
    end
    object blocksCDSLFixativeProtocol: TStringField
      FieldKind = fkLookup
      FieldName = 'LFixativeProtocol'
      LookupDataSet = fixativeTBL
      LookupKeyFields = 'id'
      LookupResultField = 'protocol'
      KeyFields = 'fixative_protocol'
      Lookup = True
    end
    object blocksCDSLFixationProtocol: TStringField
      FieldKind = fkLookup
      FieldName = 'LFixationProtocol'
      LookupDataSet = fixationMethodDS
      LookupKeyFields = 'id'
      LookupResultField = 'protocol'
      KeyFields = 'fixation_protocol'
      Lookup = True
    end
    object blocksCDSLPostFixProtocol: TStringField
      FieldKind = fkLookup
      FieldName = 'LPostFixProtocol'
      LookupDataSet = postfix
      LookupKeyFields = 'id'
      LookupResultField = 'protocol'
      KeyFields = 'postfix_protocol'
      Lookup = True
    end
    object blocksCDSLCryoProtectionProtocol: TStringField
      FieldKind = fkLookup
      FieldName = 'LCryoProtectionProtocol'
      LookupDataSet = cryoprotectionDS
      LookupKeyFields = 'id'
      LookupResultField = 'protocol'
      KeyFields = 'cryoprotection_protocol'
      Size = 0
      Lookup = True
    end
    object blocksCDSLFreezingProtocol: TStringField
      FieldKind = fkLookup
      FieldName = 'LFreezingProtocol'
      LookupDataSet = freezeprotocolDS
      LookupKeyFields = 'id'
      LookupResultField = 'protocol'
      KeyFields = 'freezing_protocol'
      Lookup = True
    end
    object blocksCDSLSubstitutionProtocol: TStringField
      FieldKind = fkLookup
      FieldName = 'LSubstitutionProtocol'
      LookupDataSet = substitutionProtocol
      LookupKeyFields = 'id'
      LookupResultField = 'protocol'
      KeyFields = 'substitution_protocol'
      Lookup = True
    end
    object blocksCDSLInfiltrationProtocol: TStringField
      FieldKind = fkLookup
      FieldName = 'LInfiltrationProtocol'
      LookupDataSet = infiltrationProtocolDS
      LookupKeyFields = 'id'
      LookupResultField = 'protocol'
      KeyFields = 'infiltration_protocol'
      Lookup = True
    end
    object blocksCDSLEmbeddingProtocol: TStringField
      FieldKind = fkLookup
      FieldName = 'LEmbeddingProtocol'
      LookupDataSet = embeddingProtocolDS
      LookupKeyFields = 'id'
      LookupResultField = 'protocol'
      KeyFields = 'embedding_protocol'
      Lookup = True
    end
    object blocksCDSLUser: TStringField
      FieldKind = fkLookup
      FieldName = 'LUser'
      LookupDataSet = usersCDS
      LookupKeyFields = 'id'
      LookupResultField = 'user_name'
      KeyFields = 'created_by'
      Lookup = True
    end
  end
  object blocksProvider: TDataSetProvider
    DataSet = blocksDS
    Options = [poFetchBlobsOnDemand, poAllowCommandText, poRetainServerOrder, poUseQuoteChar]
    Left = 136
    Top = 240
  end
  object blocksDS: TSQLDataSet
    CommandText = 
      'select * from blocks WHERE process_id = :process_id ORDER by id ' +
      'DESC'
    DataSource = specimenDataSource
    MaxBlobSize = 1
    Params = <
      item
        DataType = ftInteger
        Name = 'process_id'
        ParamType = ptInput
      end>
    SQLConnection = SQLConnection1
    Left = 40
    Top = 240
    object blocksDSid: TIntegerField
      FieldName = 'id'
    end
    object blocksDSprocess_id: TIntegerField
      FieldName = 'process_id'
    end
    object blocksDScreated: TSQLTimeStampField
      FieldName = 'created'
    end
    object blocksDScreated_by: TIntegerField
      FieldName = 'created_by'
      Required = True
    end
    object blocksDSmodified: TSQLTimeStampField
      FieldName = 'modified'
    end
    object blocksDSstatus: TSmallintField
      FieldName = 'status'
      Required = True
    end
    object blocksDSlabel: TStringField
      FieldName = 'label'
      Required = True
      Size = 255
    end
    object blocksDSserial: TSmallintField
      FieldName = 'serial'
      Required = True
    end
    object blocksDSdate_embedded: TDateField
      FieldName = 'date_embedded'
    end
    object blocksDSpreprocess_treatment_protocol: TSmallintField
      FieldName = 'preprocess_treatment_protocol'
    end
    object blocksDSfixative_protocol: TSmallintField
      FieldName = 'fixative_protocol'
    end
    object blocksDSfixation_protocol: TSmallintField
      FieldName = 'fixation_protocol'
    end
    object blocksDSpostfix_protocol: TSmallintField
      FieldName = 'postfix_protocol'
    end
    object blocksDScryoprotection_protocol: TSmallintField
      FieldName = 'cryoprotection_protocol'
    end
    object blocksDSfreezing_protocol: TSmallintField
      FieldName = 'freezing_protocol'
    end
    object blocksDSsubstitution_protocol: TSmallintField
      FieldName = 'substitution_protocol'
    end
    object blocksDSinfiltration_protocol: TSmallintField
      FieldName = 'infiltration_protocol'
    end
    object blocksDSembedding_protocol: TSmallintField
      FieldName = 'embedding_protocol'
    end
  end
  object usersDS: TSQLDataSet
    CommandText = 'select * from users'
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 40
    Top = 88
    object usersDSid: TIntegerField
      FieldName = 'id'
    end
    object usersDSuser_name: TStringField
      FieldName = 'user_name'
      Required = True
      Size = 255
    end
    object usersDScreated: TSQLTimeStampField
      FieldName = 'created'
    end
  end
  object usersProvider: TDataSetProvider
    DataSet = usersDS
    Options = [poFetchBlobsOnDemand, poUseQuoteChar]
    Left = 136
    Top = 88
  end
  object usersCDS: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'usersProvider'
    AfterPost = cdsAfterPost
    Left = 240
    Top = 88
    object usersCDSid: TIntegerField
      FieldName = 'id'
    end
    object usersCDSuser_name: TStringField
      FieldName = 'user_name'
      Required = True
      Size = 255
    end
    object usersCDScreated: TSQLTimeStampField
      FieldName = 'created'
    end
  end
  object usersDataSource: TDataSource
    DataSet = usersCDS
    Left = 336
    Top = 88
  end
  object blockNotesDSource: TDataSource
    DataSet = blockNotesCDS
    Left = 368
    Top = 312
  end
  object blockNotesProvider: TDataSetProvider
    DataSet = blockNotesDS
    Left = 160
    Top = 312
  end
  object blockNotesCDS: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'blockNotesProvider'
    AfterPost = cdsAfterPost
    AfterDelete = cdsAfterDelete
    Left = 272
    Top = 312
    object blockNotesCDSid: TIntegerField
      FieldName = 'id'
      Required = True
    end
    object blockNotesCDSnote: TMemoField
      FieldName = 'note'
      Required = True
      BlobType = ftMemo
      Size = 1
    end
    object blockNotesCDScreated_on: TSQLTimeStampField
      FieldName = 'created_on'
      Required = True
    end
    object blockNotesCDScreated_by: TIntegerField
      FieldName = 'created_by'
      Required = True
    end
  end
  object noteDS: TSQLDataSet
    CommandText = 'select * from notes'
    DataSource = notesDSource
    MaxBlobSize = 1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 472
    Top = 56
  end
  object notesProvider: TDataSetProvider
    DataSet = noteDS
    Left = 568
    Top = 56
  end
  object notesCDS: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'notesProvider'
    AfterPost = cdsAfterPost
    Left = 672
    Top = 56
    object notesCDSid: TIntegerField
      FieldName = 'id'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object notesCDSnote: TMemoField
      FieldName = 'note'
      Required = True
      BlobType = ftMemo
      Size = 1
    end
    object notesCDScreated_on: TSQLTimeStampField
      FieldName = 'created_on'
      Required = True
    end
    object notesCDScreated_by: TIntegerField
      FieldName = 'created_by'
      Required = True
    end
  end
  object notesDSource: TDataSource
    DataSet = notesCDS
    Left = 768
    Top = 56
  end
  object mRibbonProvider: TDataSetProvider
    DataSet = ribbonsDS
    Left = 128
    Top = 392
  end
  object mRibbonCDS: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'mRibbonProvider'
    BeforePost = cdsBeforePost
    AfterPost = cdsAfterPost
    AfterDelete = cdsAfterDelete
    AfterScroll = cdsAfterScroll
    AfterRefresh = cdsAfterRefresh
    OnCalcFields = mRibbonCDSCalcFields
    Left = 240
    Top = 392
    object mRibbonCDSid: TStringField
      FieldName = 'id'
      Size = 36
    end
    object mRibbonCDSstatus: TIntegerField
      FieldName = 'status'
    end
    object mRibbonCDSblock_id: TIntegerField
      FieldName = 'block_id'
      Required = True
    end
    object mRibbonCDScutting_order: TIntegerField
      FieldName = 'cutting_order'
    end
    object mRibbonCDSnr_of_sections: TSmallintField
      FieldName = 'nr_of_sections'
    end
    object mRibbonCDScreated: TSQLTimeStampField
      FieldName = 'created'
      OnGetText = TimeStampGetText
    end
    object mRibbonCDSmodified: TSQLTimeStampField
      FieldName = 'modified'
    end
    object mRibbonCDScreated_by: TIntegerField
      FieldName = 'created_by'
      Required = True
    end
    object mRibbonCDScoverslip_id: TIntegerField
      FieldName = 'coverslip_id'
      Required = True
    end
  end
  object mRibbonDSource: TDataSource
    DataSet = mRibbonCDS
    Left = 336
    Top = 392
  end
  object ribbonNotesProvider: TDataSetProvider
    DataSet = ribbonNotesDS
    Left = 152
    Top = 472
  end
  object ribbonNotesCDS: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'ribbonNotesProvider'
    AfterPost = cdsAfterPost
    Left = 264
    Top = 472
    object ribbonNotesCDSid: TIntegerField
      FieldName = 'id'
      Required = True
    end
    object ribbonNotesCDSnote: TMemoField
      FieldName = 'note'
      Required = True
      BlobType = ftMemo
      Size = 1
    end
    object ribbonNotesCDScreated_on: TSQLTimeStampField
      FieldName = 'created_on'
      Required = True
    end
    object ribbonNotesCDScreated_by: TIntegerField
      FieldName = 'created_by'
      Required = True
    end
  end
  object ribbonNotesDSource: TDataSource
    DataSet = ribbonNotesCDS
    Left = 360
    Top = 472
  end
  object ribbonsDS: TSQLDataSet
    CommandText = 'SELECT * from ribbons where block_id=:id'
    DataSource = blocksDataSource
    MaxBlobSize = -1
    Params = <
      item
        DataType = ftInteger
        Name = 'id'
        ParamType = ptInput
      end>
    SQLConnection = SQLConnection1
    Left = 32
    Top = 392
    object ribbonsDSid: TStringField
      FieldName = 'id'
      Size = 36
    end
    object ribbonsDSstatus: TIntegerField
      FieldName = 'status'
    end
    object ribbonsDSblock_id: TIntegerField
      FieldName = 'block_id'
      Required = True
    end
    object ribbonsDScutting_order: TIntegerField
      FieldName = 'cutting_order'
    end
    object ribbonsDSnr_of_sections: TSmallintField
      FieldName = 'nr_of_sections'
    end
    object ribbonsDScreated: TSQLTimeStampField
      FieldName = 'created'
    end
    object ribbonsDSmodified: TSQLTimeStampField
      FieldName = 'modified'
    end
    object ribbonsDScreated_by: TIntegerField
      FieldName = 'created_by'
      Required = True
    end
    object ribbonsDScoverslip_id: TIntegerField
      FieldName = 'coverslip_id'
      Required = True
    end
  end
  object blockNotesDS: TSQLDataSet
    CommandText = 
      'SELECT * FROM notes n '#13#10'INNER JOIN block_note bn '#13#10'ON (bn.note_i' +
      'd = n.id) '#13#10'WHERE block_id = :id '#13#10'ORDER BY created_on ASC'
    DataSource = blocksDataSource
    MaxBlobSize = 1
    Params = <
      item
        DataType = ftInteger
        Name = 'id'
        ParamType = ptInput
      end>
    SQLConnection = SQLConnection1
    Left = 64
    Top = 312
    object blockNotesDSid: TIntegerField
      FieldName = 'id'
      Required = True
    end
    object blockNotesDSnote: TMemoField
      FieldName = 'note'
      Required = True
      BlobType = ftMemo
      Size = 1
    end
    object blockNotesDScreated_on: TSQLTimeStampField
      FieldName = 'created_on'
      Required = True
    end
    object blockNotesDScreated_by: TIntegerField
      FieldName = 'created_by'
      Required = True
    end
  end
  object ribbonNotesDS: TSQLDataSet
    CommandText = 
      'SELECT * FROM notes n '#13#10'INNER JOIN ribbon_note rn '#13#10'ON (rn.note_' +
      'id = n.id) '#13#10'WHERE ribbon_id = :id '#13#10'ORDER BY created_on ASC'
    DataSource = mRibbonDSource
    MaxBlobSize = 1
    Params = <
      item
        DataType = ftString
        Name = 'id'
        ParamType = ptInput
      end>
    SQLConnection = SQLConnection1
    Left = 48
    Top = 472
    object ribbonNotesDSid: TIntegerField
      FieldName = 'id'
      Required = True
    end
    object ribbonNotesDSnote: TMemoField
      FieldName = 'note'
      BlobType = ftMemo
      Size = 1
    end
    object ribbonNotesDScreated_on: TSQLTimeStampField
      FieldName = 'created_on'
    end
    object ribbonNotesDScreated_by: TIntegerField
      FieldName = 'created_by'
    end
  end
  object specimenDS: TSQLDataSet
    CommandText = 'SELECT * from specimens order by process_id DESC'
    MaxBlobSize = 1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 32
    Top = 160
    object specimenDSprocess_id: TIntegerField
      FieldName = 'process_id'
    end
    object specimenDSspecimen_id: TStringField
      FieldName = 'specimen_id'
      Required = True
      Size = 255
    end
    object specimenDSspecie: TSmallintField
      FieldName = 'specie'
    end
    object specimenDSadditional_identifier: TStringField
      FieldName = 'additional_identifier'
      Size = 255
    end
    object specimenDSage: TStringField
      FieldName = 'age'
      Size = 255
    end
    object specimenDSlims_number: TIntegerField
      FieldName = 'lims_number'
    end
    object specimenDSdeath_date: TDateField
      FieldName = 'death_date'
    end
    object specimenDSbrain_region_dissection: TStringField
      FieldName = 'brain_region_dissection'
      Size = 255
    end
    object specimenDSdate_received: TDateField
      FieldName = 'date_received'
    end
    object specimenDSdate_entered: TSQLTimeStampField
      FieldName = 'date_entered'
    end
    object specimenDSentered_by: TIntegerField
      FieldName = 'entered_by'
      Required = True
    end
  end
  object specimenProvider: TDataSetProvider
    DataSet = specimenDS
    Options = [poAutoRefresh, poUseQuoteChar]
    Left = 136
    Top = 160
  end
  object specimenCDS: TClientDataSet
    Aggregates = <>
    FieldDefs = <
      item
        Name = 'process_id'
        DataType = ftInteger
      end
      item
        Name = 'specimen_id'
        Attributes = [faRequired]
        DataType = ftString
        Size = 255
      end
      item
        Name = 'specie'
        DataType = ftSmallint
      end
      item
        Name = 'additional_identifier'
        DataType = ftString
        Size = 255
      end
      item
        Name = 'age'
        DataType = ftString
        Size = 255
      end
      item
        Name = 'lims_number'
        DataType = ftInteger
      end
      item
        Name = 'death_date'
        DataType = ftDate
      end
      item
        Name = 'brain_region_dissection'
        DataType = ftString
        Size = 255
      end
      item
        Name = 'date_received'
        DataType = ftDate
      end
      item
        Name = 'date_entered'
        DataType = ftTimeStamp
      end
      item
        Name = 'entered_by'
        Attributes = [faRequired]
        DataType = ftInteger
      end>
    IndexDefs = <>
    Params = <>
    ProviderName = 'specimenProvider'
    StoreDefs = True
    AfterOpen = specimenCDSAfterOpen
    BeforeClose = specimenCDSBeforeClose
    AfterClose = specimenCDSAfterClose
    AfterPost = cdsAfterPost
    AfterScroll = cdsAfterScroll
    BeforeRefresh = cdsBeforeRefresh
    AfterRefresh = cdsAfterRefresh
    Left = 248
    Top = 160
    object specimenCDSprocess_id: TIntegerField
      DisplayLabel = 'Process ID'
      FieldName = 'process_id'
    end
    object specimenCDSspeciment_id: TStringField
      DisplayLabel = 'Specimen ID'
      FieldName = 'specimen_id'
      Required = True
      Size = 255
    end
    object specimenCDSspecies: TIntegerField
      DisplayLabel = 'Species'
      FieldName = 'specie'
    end
    object specimenCDSadditional_identifier: TStringField
      DisplayLabel = 'Additional Identifier'
      FieldName = 'additional_identifier'
      Size = 255
    end
    object specimenCDSage: TStringField
      DisplayLabel = 'Age'
      FieldName = 'age'
      Size = 255
    end
    object specimenCDSlims_number: TIntegerField
      DisplayLabel = 'LIMS'
      FieldName = 'lims_number'
    end
    object specimenCDSdeath_date: TDateField
      DisplayLabel = 'DOD'
      FieldName = 'death_date'
    end
    object specimenCDSbrain_region_dissection: TStringField
      DisplayLabel = 'From Brain Region'
      FieldName = 'brain_region_dissection'
      Size = 255
    end
    object specimenCDSdate_received: TDateField
      DisplayLabel = 'Date Received'
      FieldName = 'date_received'
    end
    object specimenCDSLspecie: TStringField
      DisplayLabel = 'Specie'
      FieldKind = fkLookup
      FieldName = 'Lspecie'
      LookupDataSet = speciesDS
      LookupKeyFields = 'id'
      LookupResultField = 'name'
      KeyFields = 'specie'
      Size = 255
      Lookup = True
    end
    object specimenCDSdate_entered: TSQLTimeStampField
      FieldName = 'date_entered'
    end
    object specimenCDSentered_by: TIntegerField
      FieldName = 'entered_by'
      Required = True
    end
  end
  object specimenDataSource: TDataSource
    DataSet = specimenCDS
    Left = 344
    Top = 160
  end
  object fixativeTBL: TSimpleDataSet
    Aggregates = <>
    Connection = SQLConnection1
    DataSet.CommandText = 'SELECT * from fixativeprotocols'
    DataSet.MaxBlobSize = -1
    DataSet.Params = <>
    Params = <>
    AfterPost = fixativeTBLAfterPost
    Left = 472
    Top = 504
  end
  object speciesDS: TSimpleDataSet
    Aggregates = <>
    Connection = SQLConnection1
    DataSet.CommandText = 'SELECT * from species'
    DataSet.MaxBlobSize = -1
    DataSet.Params = <>
    Params = <>
    Left = 472
    Top = 568
  end
  object preprocesstreatmentDS: TSimpleDataSet
    Aggregates = <>
    Connection = SQLConnection1
    DataSet.CommandText = 'select * from  preprocesstreatmentprotocols'
    DataSet.MaxBlobSize = -1
    DataSet.Params = <>
    Params = <>
    Left = 472
    Top = 632
  end
  object fixationMethodDS: TSimpleDataSet
    Aggregates = <>
    Connection = SQLConnection1
    DataSet.CommandText = 'select * from `fixationprotocols`'
    DataSet.MaxBlobSize = -1
    DataSet.Params = <>
    Params = <>
    Left = 568
    Top = 504
  end
  object postfix: TSimpleDataSet
    Aggregates = <>
    Connection = SQLConnection1
    DataSet.CommandText = 'select * from postfixprotocols'
    DataSet.MaxBlobSize = -1
    DataSet.Params = <>
    Params = <>
    Left = 568
    Top = 568
  end
  object cryoprotectionDS: TSimpleDataSet
    Aggregates = <>
    Connection = SQLConnection1
    DataSet.CommandText = 'select * from cryoprotectionprotocols'
    DataSet.MaxBlobSize = -1
    DataSet.Params = <>
    Params = <>
    Left = 576
    Top = 632
  end
  object freezeprotocolDS: TSimpleDataSet
    Aggregates = <>
    Connection = SQLConnection1
    DataSet.CommandText = 'select * from freezeprotocols'
    DataSet.MaxBlobSize = -1
    DataSet.Params = <>
    Params = <>
    Left = 672
    Top = 504
  end
  object substitutionProtocol: TSimpleDataSet
    Aggregates = <>
    Connection = SQLConnection1
    DataSet.CommandText = 'select * from substitutionprotocols'
    DataSet.MaxBlobSize = -1
    DataSet.Params = <>
    FieldDefs = <
      item
        Name = 'id'
        Attributes = [faRequired]
        DataType = ftSmallint
      end
      item
        Name = 'protocol'
        DataType = ftString
        Size = 255
      end
      item
        Name = 'document_id'
        DataType = ftInteger
      end>
    IndexDefs = <>
    Params = <>
    StoreDefs = True
    Left = 720
    Top = 408
    object substitutionProtocolid: TSmallintField
      FieldName = 'id'
      Required = True
    end
    object substitutionProtocolprotocol: TStringField
      FieldName = 'protocol'
      Size = 255
    end
    object substitutionProtocoldocument_id: TIntegerField
      FieldName = 'document_id'
    end
    object substitutionProtocolLDocument: TStringField
      FieldKind = fkLookup
      FieldName = 'LDocument'
      LookupDataSet = documentsCDS
      LookupKeyFields = 'document_name'
      LookupResultField = 'id'
      KeyFields = 'document_id'
      Lookup = True
    end
  end
  object infiltrationProtocolDS: TSimpleDataSet
    Aggregates = <>
    Connection = SQLConnection1
    DataSet.CommandText = 'select * from infiltrationprotocols'
    DataSet.MaxBlobSize = -1
    DataSet.Params = <>
    Params = <>
    Left = 672
    Top = 632
  end
  object embeddingProtocolDS: TSimpleDataSet
    Aggregates = <>
    Connection = SQLConnection1
    DataSet.CommandText = 'select * from embeddingprotocols'
    DataSet.MaxBlobSize = -1
    DataSet.Params = <>
    Params = <>
    Left = 784
    Top = 504
  end
  object blockstatusDS: TSimpleDataSet
    Aggregates = <>
    Connection = SQLConnection1
    DataSet.CommandText = 'SELECT * from blockstatuses'
    DataSet.MaxBlobSize = -1
    DataSet.Params = <>
    Params = <>
    AfterPost = fixativeTBLAfterPost
    Left = 472
    Top = 440
  end
  object processIDDS: TSimpleDataSet
    Aggregates = <>
    Connection = SQLConnection1
    DataSet.CommandText = 'SELECT process_id  FROM specimens'
    DataSet.MaxBlobSize = -1
    DataSet.Params = <>
    Params = <>
    Left = 488
    Top = 240
    object processIDDSprocess_id: TIntegerField
      FieldName = 'process_id'
      Required = True
    end
  end
  object documentsDS: TSQLDataSet
    CommandText = 'SELECT * from documents'
    MaxBlobSize = 1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 32
    Top = 576
    object documentsDSid: TIntegerField
      FieldName = 'id'
      Required = True
    end
    object documentsDSdocument_name: TStringField
      FieldName = 'document_name'
      Required = True
      Size = 255
    end
    object documentsDSdocument: TBlobField
      FieldName = 'document'
      Size = 1
    end
    object documentsDStype: TStringField
      FieldName = 'type'
      Size = 16
    end
  end
  object documentsProvider: TDataSetProvider
    DataSet = documentsDS
    Left = 136
    Top = 576
  end
  object documentsCDS: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'documentsProvider'
    Left = 256
    Top = 576
    object documentsCDSid: TIntegerField
      FieldName = 'id'
      Required = True
    end
    object documentsCDSdocument_name: TStringField
      DisplayLabel = 'Name'
      FieldName = 'document_name'
      Required = True
      Size = 255
    end
    object documentsCDSdocument: TBlobField
      FieldName = 'document'
      Size = 1
    end
    object documentsCDStype: TStringField
      DisplayLabel = 'Type'
      FieldName = 'type'
      Size = 16
    end
  end
  object documentsDSource: TDataSource
    DataSet = documentsCDS
    Left = 344
    Top = 568
  end
end
