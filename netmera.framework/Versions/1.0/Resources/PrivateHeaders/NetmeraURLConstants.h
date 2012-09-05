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

@interface NetmeraURLConstants : NSObject

extern NSString * const UC_HTTP_POST;
extern NSString * const UC_HTTP_GET;

extern NSString * const UC_SERVICE_NAME;
extern NSString * const UC_CONTENT_TYPE_NAME;
extern NSString * const UC_CREATE_ACTION_NAME;
extern NSString * const UC_UPDATE_ACTION_NAME;

extern NSString * const UC_DEFAULT_PARENT_PATH;
extern NSString * const UC_DEFAULT_NETMERA_URL;
extern NSString * const UC_CDN_DOMAIN;
extern NSString * const UC_NETMERA_DOMAIN;

extern NSString * const UC_API_CONTENT_TYPE;
extern NSString * const UC_PEOPLE_PATH;
extern NSString * const UC_PRIVACY_PUBLIC;

/**************************Netmera Media Constants**********************************************/

extern NSString * const UC_UPLOAD_URL;
extern NSString * const UC_SWF_URL;
extern NSString * const UC_SAVE_PHOTO_URL;

extern NSString * const UC_UPLOAD_URL_PARAMS_ST;
extern NSString * const UC_UPLOAD_URL_PARAMS_CONTENT_PATH;
extern NSString * const UC_UPLOAD_URL_PARAMS_OPENSOCIAL_VIEWER_ID;
extern NSString * const UC_UPLOAD_URL_PARAMS_OPENSOCIAL_NETMERA_DOMAIN;
extern NSString * const UC_UPLOAD_URL_PARAMS_OPENSOCIAL_APP_ID;

extern NSString * const UC_SWF_URL_PARAMS_UPLOAD_TYPE;

extern NSString * const UC_SAVE_PHOTO_URL_PARAMS_ST;
extern NSString * const UC_SAVE_PHOTO_URL_PARAMS_ALBUM;
extern NSString * const UC_SAVE_PHOTO_URL_PARAMS_UPLOADED_PHOTO_HASH;
extern NSString * const UC_SAVE_PHOTO_URL_PARAMS_PRIVACY;
extern NSString * const UC_SAVE_PHOTO_URL_PARAMS_CDN_DOMAIN;
extern NSString * const UC_SAVE_PHOTO_URL_PARAMS_OPENSOCIAL_APP_ID;
extern NSString * const UC_SAVE_PHOTO_URL_PARAMS_OPENSOCIAL_NETMERA_DOMAIN;
extern NSString * const UC_SAVE_PHOTO_URL_PARAMS_OPENSOCIAL_VIEWER_ID;

extern NSString * const UC_PARAMS_SPLITTER;

extern NSString * const UC_SITE;
extern NSString * const UC_DOMAIN;
extern NSString * const UC_PATH;
extern NSString * const UC_ALBUM_LIST;
extern NSString * const UC_UPLOAD_KEY;

extern NSString * const UC_LOCATION_SEARCH_TYPE_CIRCLE;
extern NSString * const UC_LOCATION_SEARCH_TYPE_BOX;

/**** ios **/
extern NSString * const UC_REST_RPC;
extern NSString * const UC_CREATE_ACTION_TOKEN_URL;
extern NSString * const UC_CREATE_CONTENT_URL;
extern NSString * const UC_UPDATE_CONTENT_URL;
extern NSString * const UC_DELETE_CONTENT_URL;
extern NSString * const UC_SEARCH_CONTENT_URL;
extern NSString * const UC_GET_CONTENT_URL;
extern NSString * const UC_LOCATION_SEARCH_CONTENT_URL;
//user
extern NSString * const UC_REST_REGISTER_USER_URL;
extern NSString * const UC_REST_PEOPLE_PROFILE_UPDATE_URL;
extern NSString * const UC_REST_PEOPLE_ACCOUNT_UPDATE;
extern NSString * const UC_REST_LOGIN_USER;
extern NSString * const UC_REST_PEOPLE_SEARCH;

//push

extern NSString * const URL_REGISTER;
extern NSString * const URL_UNREGISTER;

@end
