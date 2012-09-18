/*
 * Copyright 2012 Inomera Research
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>


@interface NetmeraError : NSObject{
     enum ErrorCode {
		EC_IO_EXCEPTION,
		EC_REQUIRED_FIELD,
		EC_INVALID_REQUEST,
		EC_JSON_PUT_EXCEPTION,
		EC_JSON_GET_EXCEPTION,
		EC_NULL_EXCEPTION,
		EC_INVALID_DATA_TYPE,
		EC_INVALID_DATE_FORMAT,
		EC_INVALID_URL,
        EC_ALREADY_REGISTERED_EMAIL,
        EC_NOT_REGISTERED_EMAIL,
        EC_DISTANCE_EXEPTION
     };
}


+ (NSError *) createIOError;
+ (NSError *) createREQUIRED_FIELDErrorWithString:(NSString *)requiredField;
+ (NSError *) createINVALID_REQUESTError;
+ (NSError *) createJSON_PUTErrorWithString:(NSString *)key value:(id)value;
+ (NSError *) createJSON_GETErrorWithString:(NSString *)key;
+ (NSError *) createNULLErrorWithString:(NSString *)key;
+ (NSError *) createINVALID_DATA_TYPEErrorWithString:(NSString *)dataTypeName;
+ (NSError *) createINVALID_DATE_FORMATError;
+ (NSError *) createINVALID_URLErrorWithString:(NSString *)urlString;
+ (NSError *) createALREADY_REGISTERED_EMAILError;
+ (NSError *) createNOT_REGISTERED_EMAILErrorWithString:(NSString *)errorMessage;
+ (NSError *) createEC_DISTANCEError;

@end
