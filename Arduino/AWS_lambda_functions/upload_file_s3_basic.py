# I have to merge function this and anoter function tha can get information from device shadow

import boto3
from datetime import datetime

print('Loading function')

s3 = boto3.resource('s3')

def lambda_handler(event, context):
    
    bucket = 'smart-watch-project'
    key = 'test_' + datetime.now().strftime('%Y-%m-%d-%H-%M-%S') + '.text'
    file_contents = 'Lambda test'

    obj = s3.Object(bucket,key)
    obj.put(Body=file_contents)
    return
