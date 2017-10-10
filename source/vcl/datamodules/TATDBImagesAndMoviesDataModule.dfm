object ImagesAndMoviesDM: TImagesAndMoviesDM
  OldCreateOrder = False
  Height = 591
  Width = 866
  object images: TSQLDataSet
    CommandText = 'select * from umimage order by date desc'
    MaxBlobSize = -1
    Params = <>
    Left = 40
    Top = 112
    object imagesid: TIntegerField
      FieldName = 'id'
      Required = True
    end
    object imagesfile_name: TStringField
      FieldName = 'file_name'
      Required = True
      Size = 512
    end
    object imagesdate: TSQLTimeStampField
      FieldName = 'date'
      Required = True
    end
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = imageNotesDS
    Left = 144
    Top = 184
  end
  object imagesProvider: TDataSetProvider
    DataSet = images
    Left = 144
    Top = 112
  end
  object imagesCDS: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'imagesProvider'
    AfterScroll = imagesCDSAfterScroll
    Left = 256
    Top = 112
    object imagesCDSid: TIntegerField
      FieldName = 'id'
      Required = True
    end
    object imagesCDSfile_name: TStringField
      FieldName = 'file_name'
      Required = True
      Size = 512
    end
    object imagesCDSdate: TSQLTimeStampField
      FieldName = 'date'
      Required = True
    end
  end
  object imagesDS: TDataSource
    DataSet = imagesCDS
    Left = 360
    Top = 112
  end
  object imageNotesDSource: TDataSource
    DataSet = imageNoteCDS
    Left = 360
    Top = 184
  end
  object imageNoteCDS: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider1'
    Left = 256
    Top = 184
    object imageNoteCDSid: TIntegerField
      FieldName = 'id'
    end
    object imageNoteCDSnote: TMemoField
      FieldName = 'note'
      BlobType = ftMemo
      Size = 1
    end
    object imageNoteCDScreated_on: TSQLTimeStampField
      FieldName = 'created_on'
    end
    object imageNoteCDScreated_by: TIntegerField
      FieldName = 'created_by'
    end
    object imageNoteCDSimage_id: TIntegerField
      FieldName = 'image_id'
    end
    object imageNoteCDSnote_id: TIntegerField
      FieldName = 'note_id'
    end
  end
  object sensors: TSQLDataSet
    CommandText = 'select * from sensor_data order by date desc'
    MaxBlobSize = -1
    Params = <>
    Left = 40
    Top = 344
    object sensorsid: TIntegerField
      FieldName = 'id'
    end
    object sensorsdevice_id: TIntegerField
      FieldName = 'device_id'
    end
    object sensorsdate: TSQLTimeStampField
      FieldName = 'date'
    end
    object sensorstemperature: TFloatField
      FieldName = 'temperature'
    end
    object sensorshumidity: TFloatField
      FieldName = 'humidity'
    end
  end
  object DataSetProvider3: TDataSetProvider
    DataSet = sensors
    Left = 144
    Top = 344
  end
  object sensorsCDS: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider3'
    AfterScroll = imagesCDSAfterScroll
    Left = 256
    Top = 344
    object sensorsCDSdevice_id: TIntegerField
      FieldName = 'device_id'
    end
    object sensorsCDSdate: TSQLTimeStampField
      FieldName = 'date'
    end
    object sensorsCDStemperature: TFloatField
      FieldName = 'temperature'
    end
    object sensorsCDShumidity: TFloatField
      FieldName = 'humidity'
    end
  end
  object sensorsDS: TDataSource
    DataSet = sensorsCDS
    Left = 336
    Top = 344
  end
  object imageNotesDS: TSQLDataSet
    CommandText = 
      'SELECT * FROM note n '#13#10'INNER JOIN umimage_note uin '#13#10'ON (uin.not' +
      'e_id = n.id) '#13#10'WHERE image_id = :id '#13#10'ORDER BY created_on ASC'
    DataSource = imagesDS
    MaxBlobSize = 1
    Params = <
      item
        DataType = ftInteger
        Name = 'id'
        ParamType = ptInput
      end>
    Left = 40
    Top = 184
    object imageNotesDSid: TIntegerField
      FieldName = 'id'
    end
    object imageNotesDSnote: TMemoField
      FieldName = 'note'
      BlobType = ftMemo
      Size = 1
    end
    object imageNotesDScreated_on: TSQLTimeStampField
      FieldName = 'created_on'
    end
    object imageNotesDScreated_by: TIntegerField
      FieldName = 'created_by'
    end
    object imageNotesDSimage_id: TIntegerField
      FieldName = 'image_id'
    end
    object imageNotesDSnote_id: TIntegerField
      FieldName = 'note_id'
    end
  end
  object notesDSource: TDataSource
    DataSet = notesCDS
    Left = 716
    Top = 64
  end
  object notesCDS: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'notesProvider'
    Left = 628
    Top = 64
    object IntegerField1: TIntegerField
      FieldName = 'id'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object MemoField1: TMemoField
      FieldName = 'note'
      Required = True
      BlobType = ftMemo
      Size = 1
    end
    object SQLTimeStampField1: TSQLTimeStampField
      FieldName = 'created_on'
      Required = True
    end
    object IntegerField2: TIntegerField
      FieldName = 'created_by'
      Required = True
    end
  end
  object notesProvider: TDataSetProvider
    DataSet = noteDS
    Left = 540
    Top = 64
  end
  object noteDS: TSQLDataSet
    CommandText = 'select * from note'
    DataSource = notesDSource
    MaxBlobSize = 1
    Params = <>
    Left = 448
    Top = 64
  end
end
