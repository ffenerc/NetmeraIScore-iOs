/**
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
#import "JSONKit.h"

/**
 NetmeraGeoLocation is used to create location with the given latitude and
 longitude values. It is used to set location into the content and then use it
 on the search queries.
 */
@interface NetmeraGeoLocation : NSObject


@property(nonatomic,setter = setLatitude:)double latitude;

@property(nonatomic,setter = setLongitude:)double longitude;

/**
 Creates location with the given latitude and longitude.
 
 @param latitude must be between the range of (-90,90)
 @param longitude must be between the range of (-180,180)
 */
-(id)initWithLatitude:(double)latitude andLongitude:(double)longitude;

/**
 Set latitude into the location. Latitude must be between the range of (-90.0, 90.0).
 
 @param latitude Location's latitude
 */
-(void)setLatitude:(double)latitude;

/**
 Set longitude into the location. Longitude must be between the range of (-180.0, 180.0).
 @param longitude Location's longitude
 */
-(void)setLongitude:(double)longitude;

@end


/**
 NetmeraClient class contains the configuration methods. 
 */
@interface NetmeraClient : NSObject{
    /** 
     Types of the Cache to use while searching. 
     */
    enum CacheType{
		/** 
         Queries does not add and retrieve results to cache. 
         */
		DEFAULT_NO_CACHE,
        
		/** 
         Queries retrieve results from the cache.
         */
		FROM_CACHE,
        
		/**
		 Queries retrieve results from the network and add results into the
		 cache.
		 */
		FROM_NETWORK,
        
		/**
		 Queries first tries to get results from cache, if it cannot find then
		 tries to get from network.
		 */
		FIRST_CACHE_THEN_NETWORK,
        
		/**
		 Queries first tries to get results from network, if it cannot find
		 then tries to get from cache.
		 */
		FIRST_NETWORK_THEN_CACHE
	};
}

/**
 Types of the Cache to use while searching.
 @warning enum CacheType options.
 
 Queries does not add and retrieve results to cache.
    DEFAULT_NO_CACHE,
 Queries retrieve results from the cache.
    FROM_CACHE,
 Queries retrieve results from the network and add results into the
 cache.
    FROM_NETWORK,
 Queries first tries to get results from cache, if it cannot find then
 tries to get from network.
    FIRST_CACHE_THEN_NETWORK,
 Queries first tries to get results from network, if it cannot find
 then tries to get from cache.
    FIRST_NETWORK_THEN_CACHE
 */
@property(nonatomic)enum CacheType cacheType;

/**
 Set cache method of netmera
 @param cacheType Type of the cache method
 @warning enum CacheType options.
 
 Queries does not add and retrieve results to cache.
    DEFAULT_NO_CACHE,
 Queries retrieve results from the cache.
    FROM_CACHE,
 Queries retrieve results from the network and add results into the
 cache.
    FROM_NETWORK,
 Queries first tries to get results from cache, if it cannot find then
 tries to get from network.
    FIRST_CACHE_THEN_NETWORK,
 Queries first tries to get results from network, if it cannot find
 then tries to get from cache.
    FIRST_NETWORK_THEN_CACHE
 */
+(void)setCacheType:(enum CacheType) cacheType;

/**
 Deletes everything from the cache
 */
+(void) deleteCacheResults;

/**
 Authenticates user and application. It is recommended to call this method
 at the beginning of the program.
 @param apiKey key that given from Netmera account of your project
 */
+ (void)initWithApiKey:(NSString *)apiKey;

- (NSData *) sendHttpGETWithUrlString:(NSString *)urlString error:(NSError **)error;

- (NSData *) sendHttpPostWithUrlString:(NSString *)urlString parametersMap:(NSDictionary *)dictionary error:(NSError **)error;

- (NSData *) sendWithUrl:(NSString *)urlString parametersMap:(NSDictionary *)dictionary withHTTPMethod:(NSString *)httpMethod error:(NSError **)error isCacheEnable:(BOOL)isCacheEnable;

- (NSData *) sendForOpenSocialWithUrl:(NSString *)urlString rest:(NSString *)rest parametersMap:(NSDictionary *)dictionary withHTTPMethod:(NSString *)httpMethod error:(NSError **)error;

- (NSData *) sendwithHttpBoddy:(NSData *)data url:(NSString *)urlString parametersMap:(NSDictionary *)dictionary withHTTPMethod:(NSString *)httpMethod error:(NSError **)error;

@end

/**
 NetmeraMedia object is used to create media content.
 <p>
 Its constructor is used to create different types of media content.
 </p>
 */
@interface NetmeraMedia : NSObject{
    
    enum PhotoSize {
		DEFAULT,
        
		THUMBNAIL,
		
		SMALL,
        
		MEDIUM,
        
		LARGE
	};
    
    
    NSData *data;
    

	NSString *url;
    
	NSString *key;
    
}

@property (nonatomic, retain) NSString *key;
/** NSData that holds image data */
@property (nonatomic, retain) NSData *data;
/** Path of the media */
@property (nonatomic, retain) NSString *url;

/**
 Constructor that takes byte array as a parameter and creates NetmeraMedia object.
 
 @param data The image's data
 */
- (NetmeraMedia *) initWithData:(NSData  *) data;


/**
 
 Returns the URL of file with the given size.
 
 @param size PhotoSize object
 @return NSURL of the photo with the given size.
 */
- (NSURL *)getUrlWithPhotoSize:(enum PhotoSize)size;

@end

/**
 NetmeraUser object is for managing users of the application. You can
 register, update, login users with this class.
 */
@interface NetmeraUser : NSObject{
    
    NSString *email;
    NSString *password;
    NSString *nickname;
    NSString *name;
    NSString *surname;
    
}

@property (nonatomic, retain) NSString *email;
@property (nonatomic, retain) NSString *password;
@property (nonatomic, retain) NSString *nickname;
@property (nonatomic, retain) NSString *name;
@property (nonatomic, retain) NSString *surname;


/**
 Returns the current logged user. If no user logged in then it returns nil.
 
 @return current user
 */

+(NetmeraUser *) getCurrentUser;

/**
 Registers new user. Before calling this method email,password and
 nickname fields of the NetmeraUser should be setted. Those are
 the compulsory fields. There are also optional name and surname fields.
 
 <br>
 <br>
 
 <code>
 NetmeraUser *user = [[NetmeraUser alloc] init];<br>
 user.email = @"test@test.com";<br>
 user.password = @"12345";<br>
 user.nickname = @"test";<br>
 NSError *err = nil;<br>
 BOOL isregistered = [user registerWithError:&err];<br>
 </code>
 
 @param error if it cannot access server
 */
-(BOOL) registerWithError:(NSError **)error;


/**
 Registers new user. Before calling this method email,password and
 nickname fields of the NetmeraUser should be setted. Those are
 the compulsory fields. There are also optional name and surname fields.
 
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void) callBackRegisterWithError:(NSError *)error. error will be nil on success and set if there was an error.
 
 */
-(void)registerInBackgroundWithTarget:(id)target selector:(SEL)selector;

/**
 Registers new user in the background thread and executes the given callback block. Before calling this method email,password and
 nickname fields of the NetmeraUser should be setted. Those are
 the compulsory fields. There are also optional name and surname fields.
 
 
 @param block The block to execute. The block should have the following argument signature: (NSError *error)
 
 */
-(void)registerInBackgroundWithBlock:(void(^)(NSError *error))block;

/**
 Updates user info. Before calling this method email,password and nickname
 fields of the NetmeraUser should be setted. Those are the
 compulsory fields.
 
 @param error if it cannot access server
 */
-(BOOL) update:(NSError **)error;

/**
 Updates user info. Before calling this method email,password and nickname
 fields of the NetmeraUser should be setted. Those are the
 compulsory fields.
 
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void) callBackUpdateWithError:(NSError *)error. error will be nil on success and set if there was an error.
 
 */
- (void)updateInBackgroundWithTarget:(id)target selector:(SEL)selector;

/**
 Updates user info. Before calling this method email,password and nickname
 fields of the NetmeraUser should be setted. Those are the
 compulsory fields.
 
 @param block The block to execute. The block should have the following argument signature: (NSError *error)
 
 */
-(void)updateInBackgroundWithBlock:(void(^)(NSError *error))block;

/**
 Logs a user into the registered application. Email and password fields of
 user is used for this operation.
 
 @param email of the user
 @param password of the user
 @param error if it cannot access server
 @return the logged User
 */
+(NetmeraUser *) loginWithEmail:(NSString *)email andPassword:(NSString *)password withError:(NSError **)error;

/**
 Logs a user into the registered application. Email and password fields of user is used for this operation.
 
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void) callBackLoginWithError:(NSError *)error withNetmeraUser:(NetmeraUser *)user. error will be nil on success and set if there was an error.
 
 @param email of the user
 @param password of the user
 */
+ (void)loginInBackgroundWithTarget:(id)target selector:(SEL)selector withEmail:(NSString *)email andPassword:(NSString *)password;


/**
 User logged out from the application.
 */
+(void) logout;

/**
 Activates the registered User.
 
 @param email of the user
 @param error if it cannot access server
 */
-(BOOL) activateUserWithEmail:(NSString *)email andError:(NSError **)error;

/**
 Deactivates the registered User
 
 @param email of the user
 @param error if it cannot access server
 */
-(BOOL) deactivateUserWithEmail:(NSString *)email andError:(NSError **)error;

@end

/**
 Cache mechanism for IPhone API
 */
@interface NetmeraCache : NSObject

@end

/**
 The NetmeraContent object is used to run CRUD operations over the data.
 <p>
 After creating object use add method to fill data and call create method
 to add data into cloud.
 </p>
\*/
@interface NetmeraContent : NSObject {
    
    
    NSString *objectName;
    
	NSString *path;
    
	NSString *createDate;
    
	NSString *updateDate;
    
    
    NSMutableDictionary *data;
    NSMutableDictionary *mediaData;
    NSMutableDictionary *content;
    NSMutableDictionary *owner;
    NSMutableDictionary *contentType;
    
}


/** Name of the content */
@property(readonly) NSString *objectName;

/** Path to the content */
@property(nonatomic, retain) NSString *path;

/** Create date of the NetmeraContent object */
@property(readonly) NSString *createDate;

/** Update date of the NetmeraContent object */
@property(readonly) NSString *updateDate;


@property(readonly) NSMutableDictionary *data;
@property(readonly) NSMutableDictionary *mediaData;
@property(nonatomic,retain) NSMutableDictionary *content;
@property(nonatomic,retain) NSMutableDictionary *owner;
@property(nonatomic,retain) NSMutableDictionary *contentType;

/**
 Constructor that takes content name as parameter.
 @param objectName Name of the content
 */
- (NetmeraContent *) initWithObjectName:(NSString *) objectName;

/**
 Adds data to the cloud.
 
 @param error if it cannot access server
 */
- (BOOL) create:(NSError**)error;

/**
 Updates data
 
 @param error if it cannot access server
 */
- (BOOL) update:(NSError **)error;

/**
 Deletes data from the cloud.
 @warning Before calling this method path of the data should be setted
 @param error if it cannot access server
 
 */
- (BOOL) delete:(NSError **)error;

/**
 Adds key,value pairs into the object. If the object contains key, the old
 value is replaced.
 
 @param key key to identify specified value
 @param value value associates with the specified key
 
 @warning Raises an exception if value is not an object that NSDictionary accepts.
 */
- (void) add:(NSString *)key object:(NSObject*) value;

/**
 Adds key,value pairs into the object. If the object contains key, the old
 value is replaced.
 
 @param key key to identify specified value
 @param value BOOL value associates with the specified key
 
 @warning Raises an exception if value is not an object that NSDictionary accepts.
 */
- (void) addBool:(NSString *)key object:(BOOL) value;

/**
 Adds data to the cloud in the background thread. Since it runs on the
 background thread it does not block program.It is recommended over
 create method.
 
 @param target The object to call selector on.
 @param selector The selector to call. It should have the following signature: (void) callBackCreateWithContent:(NetmeraContent *)content error:(NSError *)error. error will be nil on success and set if there was an error. content will be the new creates NetmeraContent object.
 */
- (void)createInBackgroundWithTarget:(id)target selector:(SEL)selector;

/**
 Adds data to the cloud in the background thread and executes the given callback block. Since it runs on the
 background thread it does not block program.It is recommended over
 create method.
 
 @param block The block to execute. The block should have the following argument signature: (NetmeraContent *content, NSError *error)
 */
- (void)createInBackgroundWithBlock:(void(^)(NetmeraContent *content, NSError *error))block;

/**
 Adds data to the cloud in the background thread. Since it runs on the
 background thread it does not block program.It is recommended over
 create method.
 */
- (void)createInBackground;

/**
 Updates data in the background thread. Since it runs on the background
 thread it does not block program.It is recommended over update method.
 
 @param target The target on which the selector will be called.
 @param selector The selector to call. It should have the following signature: (void)callBackUpdateWithContent:(NetmeraContent *)content error:(NSError *)error. error will be nil on success and set if there was an error. content will be the NetmeraContent with the updated data.
 
 */
- (void)updateInBackgroundWithTarget:(id)target selector:(SEL)selector;

/**
 Updates data in the background thread and executes. Since it runs on the background
 thread it does not block program.It is recommended over update method.
 
 @param block The block to execute. The block should have the following argument signature: (NetmeraContent *content, NSError *error)
 */
- (void)updateInBackgroundWithBlock:(void(^)(NetmeraContent *content, NSError *error))block;

/**
 Deletes data from the cloud in the background thread.Since it runs on the
 background thread it does not block program.It is recommended over
 delete method.
 
 @warning Before calling this method path of the data should be setted
 
 @param target The target on which the selector will be called.
 @param selector The selector to call. It should have the following signature: (void) callBackDeleteWithError:(NSError *)error. error will be nil on success and set if there was an error.
 */
- (void)deleteInBackgroundWithTarget:(id)target selector:(SEL)selector;

/**
 Deletes data from the cloud in the background thread and executes.Since it runs on the
 background thread it does not block program.It is recommended over
 delete method.
 
 @warning Before calling this method path of the data should be setted
 
 @param block The block to execute. The block should have the following argument signature: (NSError *error)
 */
- (void)deleteInBackgroundWithBlock:(void(^)(NSError *error))block;

/**
 Deletes data from the cloud in the background thread.Since it runs on the
 background thread it does not block program.It is recommended over
 delete method.
 
 @warning Before calling this method path of the data should be setted
 
 */
- (void)deleteInBackground;

/**
 Gets the NSObject with the specified key.
 
 @param key key to get value
 @return Returns the NSObject with the specified key.If the object type is not NSObject or key does not exists then it returns nil.
 
 */
-(NSObject*)get:(NSString*)key;


/**
 Gets the NSString object with the specified key.
 
 @param key key to get value
 @return Returns the NSString with the specified key.If the object type is not NSString or key does not exists then it returns nil.
 
 */
-(NSString*)getString:(NSString*)key;

/**
 Gets the int value with the specified key.
 
 @param key key to get value
 @return Returns the int value with the specified key.If value is not an integer or key does not exists then it returns 0.
 
 */
-(int)getInt:(NSString*)key;


/**
 Gets the long value with the specified key.
 
 @param key key to get value
 @return Returns the long value with the specified key.If value is not a long or key does not exists then it returns 0.
 
 */
-(long)getLong:(NSString*)key;


/**
 Gets the boolean value with the specified key.
 
 @param key key to get value
 @return Returns the boolean value with the specified key.If value is a boolean or key does not exists then it returns false.
 
 */
-(BOOL)getBool:(NSString*)key;


/**
 Gets the double value with the specified key.
 
 @param key key to get value
 @return Returns the double value with the specified key.If value is not a double or key does not exists then it returns 0.0.
 
 */
-(double)getDouble:(NSString*)key;


/**
 Gets the NSDictionary object with the specified key.
 
 @param key key to get value
 @return Returns the NSDictionary object with the specified key.If the object type is not an NSDictionary or key does not exists then it returns nil.
 
 */
-(NSDictionary*)getDictionary:(NSString*)key;

/**
 Gets the NSArray object with the specified key.
 
 @param key key to get value
 @return Returns the NSArray object with the specified key.If the object type is not an NSArray or key does not exists then it returns nil.
 
 */
-(NSArray*)getDictionaryArray:(NSString*)key;


/**
 Gets the NetmeraGeoLocation object with the specified key.
 
 @param key key to get value
 @return Returns the NetmeraGeoLocation object with the specified key.If the object type is not an NetmeraGeoLocation or key does not exists then it returns nil.
 
 */
-(NetmeraGeoLocation*)getNetmeraGeoLocation:(NSString*)key;

/**
 Gets the NetmeraMedia object with the specified key.
 
 @param key key to get value
 @return Returns the NetmeraMedia object with the specified key.If
 the object type is not an NetmeraMedia or key does not
 exists then it returns null.
 */

-(NetmeraMedia*)getNetmeraMedia:(NSString*)key;

/**
 Gets the NetmeraUser object with the specified key.
 
 @param key key to get value
 @return Returns the NetmeraUser object with the specified key.If
 the object type is not an NetmeraUser or key does not
 exists then it returns null.
 */
-(NetmeraUser *) getNetmeraUser:(NSString *)key;

@end

/**
 NetmeraService is used to get NetmeraContent object by its search
 and get methods. Many query options defined to help finding exact object.

 */
@interface NetmeraService : NSObject{
    enum SortOrder {
		ascending, descending
	};
    
    
}

/** Name of the content */
@property(nonatomic,retain)NSString *objectName;

/** List to add queries for the search */
@property(nonatomic,retain)NSMutableArray *queries;

/** List to add queries for the search */
@property(nonatomic,retain) NSMutableDictionary *conditionalMap;

/** Text to search */
@property(nonatomic,retain)NSString *searchText;

/**the search type*/
@property(nonatomic,retain)NSString *searchType;

/**the field that holds location info*/
@property(nonatomic,retain)NSString *locationSearchField;

/** Maximum number of the content to return */
@property(nonatomic, setter = setMax:)int max;

/** Number of the pages */
@property(nonatomic, setter = setPage:)int page;

/** Path of the content */
@property(nonatomic,retain)NSString *path;

@property(nonatomic,retain)NSString *sortBy;

@property(nonatomic)enum SortOrder sortOrder;

/**
 Default constructor for the NetmeraService that sets objectName and other default parameters.
 
 @warning Default value for the max = 10 and page = 0. It returns 10 result in each
 page. It skips page * max in each iteration.
 
 @param objectName Name of the content
 */
-(id)initWithName:(NSString*)objectName;


/**
 Gets the total number of results that matches the query.
 
 @return Returns the total number of results
 @param error if it cannot access server.
 */
-(long)count:(NSError**)error;

/**
 Gets the total number of results that match the query in the background
 thread.Since it runs on the background thread it does not block
 program.It is recommended over count method.
 
 @param target The target on which the selector will be called.
 @param selector The selector to call. It should have the following signature: (void)callBackCountWithCount:(NSNumber*)count error:(NSError *)error. error will be nil on success and set if there was an error. count will tell count of contents
 */
-(void)countInBackgroundWithTarget:(id)target selector:(SEL)selector;

/**
 Gets the total number of results that match the query in the background
 thread and executes.Since it runs on the background thread it does not block
 program.It is recommended over count method.
 
 @param block The block to execute. The block should have the following argument signature: (NSNumber *count, NSError *error)
 */
-(void)countInBackgroundWithBlock:(void(^)(NSNumber *count, NSError *error))block;

/**
 Adds the searchText into the query.
 
 @param searchText Text to search
 */
-(void)addSearchText:(NSString*)searchText;


/**
 Adds an options to the query where value that matches with the query is
 equal to the given value.
 
 @param key key to identify specified value
 @param value value associates with the specified key
 */
-(void)whereEqualWithKey:(NSString*)key  andValue:(id)value;

/**
 Adds an options to the query where value that matches with the query is
 greater than the given value.
 
 @param key key to identify specified value
 @param value value associates with the specified key
 */
-(void)whereGreatherThanWithKey:(NSString*)key andValue:(id)value;

/**
 Adds an options to the query where value that matches with the query is
 less than the given value.
 
 @param key key to identify specified value
 @param value value associates with the specified key
 */
-(void)whereLessThanWithKey:(NSString*)key andValue:(id)value;

/**
 Adds an options to the query where value that matches with the query is
 not equal to the given value.
 @param key key to identify specified value
 @param value value associates with the specified key
 */
-(void)whereNotEqualWithKey:(NSString*)key andValue:(id)value;

/**
 Adds an options to the query where value that matches with the query is
 greater than or equal to the given value.
 
 @param key key to identify specified value
 @param value value associates with the specified key
 */
-(void)whereGreatherThanOrEqualWithKey:(NSString*)key andValue:(id)value;


/**
 Adds an options to the query where value that matches with the query is
 less than or equal to the given value.
 @param key key to identify specified value
 @param value value associates with the specified key
 */
-(void)whereLessThanOrEqualWithKey:(NSString*)key andValue:(id)value;

/**
 Adds an options to the query where the given key is exists or not. If
 value is true then it checks whether key exists, if value is false then
 it checks whether key not exists.
 
 @param key key to identify specified value
 @param value BOOL value to check whether key exists or not
 */
-(void)whereExistsWithKey:(NSString*)key andValue:(BOOL)value;

/**
 Adds an options to the query where value that returns from the query
 matches with the given regex.
 
 @param key key to identify specified value
 @param regex value associates with the specified key
 */
-(void)whereMatchesWithKey:(NSString*)key andRegex:(NSString *)regex;

/**
 Adds an options to the query where value that matches with the query
 starts with the given prefix.
 @param key key to identify specified value
 @param prefix value associates with the specified key
 */
-(void)whereStartsWithWithKey:(NSString*)key andPrefix:(id)prefix;

/**
 Adds an options to the query where value that matches with the query ends
 with the given suffix.
 @param key key to identify specified value
 @param suffix value associates with the specified key
 */
-(void)whereEndsWithWithKey:(NSString*)key andSuffix:(id)suffix;

/**
 Adds an options to the query where value that matches with the query
 contains any of the values in the given collection.
 @param key key to identify specified value
 @param values values associates with the specified key
 */
-(void)whereContainedInWithKey:(NSString*)key andValues:(NSArray*)values;

/**
 Adds an options to the query where value that matches with the query
 contains all of the values in the given collection.
 @param key key to identify specified value
 @param values values associates with the specified key
 */
-(void)whereAllContaintedInWithKey:(NSString*)key andValues:(NSArray*)values;

/**
 Searches the content by taking given location as a base and retrieves the
 contents that located given distance far away.
 
 @param startLocation base location to search near it.
 @param distance is used to create circle by taking the startLocation as a center.
 @param locationSearchField name of the field that holds location data.
 @param error if it cannot access server
 @return the list of NetmeraContent object.
 
 */
-(NSArray*)circleSearchWithStartLocation:(NetmeraGeoLocation*)startLocation andDistance:(double)distance andlocationSearchField:(NSString*)locationSearchField withError:(NSError**)error;

/**
 Searches the content by taking given location as a base and retrieves the
 contents that located given distance far away in the background
 thread.Since it runs on the background thread it does not block
 program.It is recommended over circleSearch method.
 
 @param startLocation base location to search near it.
 @param distance is used to create circle by taking the startLocation as a center.
 @param locationSearchField name of the field that holds location data.
 @param target The target on which the selector will be called.
 @param selector The selector to call. It should have the following signature: callBackCircleSearchWithContentArray:(NSArray*)netmeraContentArray error:(NSError *)error. error will be nil on success and set if there was an error. netmeraContentArray(NSArray with NetmeraContent) is the result of search query.
 */
-(void)circleSearchInBackgroundWithTarget:(id)target selector:(SEL)selector startLocation:(NetmeraGeoLocation*)startLocation distance:(double)distance locationSearchField:(NSString*)locationSearchField;


/**
 Creates box using the given two location (latitude,longitude) data and
 searches inside that box.
 
 @param firstPoint NetmeraGeoLocation object
 @param secondPoint NetmeraGeoLocation object
 @param locationSearchField name of the field that holds location data.
 @param error if it cannot access server
 @return the list of NetmeraContent object.
 
 */
-(NSArray*)boxSearchWithFirstLocation:(NetmeraGeoLocation*)firstPoint andSecondPoint:(NetmeraGeoLocation*)secondPoint andlocationSearchField:(NSString*)locationSearchField withError:(NSError**)error;

/**
 Creates box using the given two location (latitude,longitude) data and
 searches inside that box in the background thread.Since it runs on the
 background thread it does not block program.It is recommended over
 boxSearch method.
 
 @param firstPoint NetmeraGeoLocation object
 @param secondPoint NetmeraGeoLocation object
 @param locationSearchField name of the field that holds location data.
 @param target The target on which the selector will be called.
 @param selector The selector to call. It should have the following signature: (void) callBackBoxSearchWithContentArray:(NSArray*)netmeraContentArray error:(NSError *)error. error will be nil on success and set if there was an error. netmeraContentArray(NSArray with NetmeraContent) is the result of search query.
 */
-(void)boxSearchInBackgroundWithTarget:(id)target selector:(SEL)selector firstLocation:(NetmeraGeoLocation*)firstPoint secondPoint:(NetmeraGeoLocation*)secondPoint locationSearchField:(NSString*)locationSearchField;

/**
 Gets the list of NetmeraContent from the network.
 @param error if it cannot access server
 */
-(NSArray*)search:(NSError**)error;

/**
 Retrieves the list of NetmeraContent objects that matches with
 the query in the background thread.Since it runs on the background thread
 it does not block program.It is recommended over search method.
 
 @param target The target on which the selector will be called.
 @param selector The selector to call. It should have the following signature: (void) callBackSearchWithContentArray:(NSArray*)netmeraContentArray error:(NSError *)error. error will be nil on success and set if there was an error. netmeraContentArray(NSArray with NetmeraContent) is the result of search query.
 */
-(void)searchInBackgroundWithTarget:(id)target selector:(SEL)selector;

/**
 Retrieves the list of NetmeraContent objects that matches with
 the query in the background thread and executes.Since it runs on the background thread
 it does not block program.It is recommended over search method.
 
 @param block The block to execute. The block should have the following argument signature: (NSArray *netmeraContentArray, NSError *error)
 */
-(void)searchInBackgroundWithBlock:(void(^)(NSArray *netmeraContentArray, NSError *error))block;

/**
 Gets the single NetmeraContent object that matches the query.
 
 @param error if it cannot access server
 */
-(NetmeraContent*)get:(NSError**)error;

/**
 Gets the single NetmeraContent object that matches the query in
 the background thread.Since it runs on the background thread it does not
 block program.It is recommended over get method.
 
 @param target The target on which the selector will be called.
 @param selector The selector to call. It should have the following signature: (void)callBackGetWithContent:(NetmeraContent *)content error:(NSError *)error. error will be nil on success and set if there was an error. content will ne the NetmeraContent object.
 */
-(void)getInBackgroundWithtTarget:(id)target selector:(SEL)selector;

/**
 Gets the single NetmeraContent object that matches the query in
 the background thread and executes.Since it runs on the background thread it does not
 block program.It is recommended over get method.
 
 @param block The block to execute. The block should have the following argument signature: (NetmeraContent *content, NSError *error)
 */
-(void)getInBackgroundWithBlock:(void(^)(NetmeraContent *content, NSError *error))block;

/**
 Gets the queries list of queries and merges them as single query.
 */
-(NSString*)getCustomCondition;

/**
 Retrieves the list of NetmeraUser objects that matches with the query.
 
 @param error if it cannot access server
 @return List of the NetmeraUser array
 */
-(NSArray *)searchUser:(NSError **)error;

@end
/**
 This is the main class to manage push notifications in Netmera. With the help
 of this class, you can register/unregister devices to get notification.
 */
@interface NetmeraPushService : NSObject

/**
 Unregisters device.
 @param token application's deviceToken
 */
+(void) unRegisterWithToken:(NSString *)token;

/**
 Unregisters device in the background thread and not callback any
 @param token application's deviceToken
 
 */
+(void) unRegisterInBackgroundWithToken:(NSString *)token;

/**
 Unregisters device in the background thread
 
 @param token application's deviceToken
 @param block The block to execute. The block should have the following argument signature: (NSError *error)
 */
+(void) unRegisterInBackgroundWithToken:(NSString *)token withBlock:(void(^)(NSError *error))block;

/**
 Registers the device into to the server.
 
 @param token application's deviceToken
 */
+(void) registerWithToken:(NSString *)token;

/**
 Registers the device into to the server in the background thread and not callback any
 @param token application's deviceToken
 
 */
+(void) registerInBackgroundWithToken:(NSString *)token;

/**
 Unregisters device in the background thread
 
 @param token application's deviceToken
 @param block The block to execute. The block should have the following argument signature: (NSError *error)
 */
+(void) registerInBackgroundWithToken:(NSString *)token withBlock:(void(^)(NSError *error))block;

@end