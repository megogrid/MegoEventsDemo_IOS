
#import <Foundation/Foundation.h>
/// @cond
@protocol ActionDelegate <NSObject>

@optional
-(void)actionSuccess;
-(void)GetEventDetailsSuccess:(NSString*)Status;
-(void)getWebServiceResponce:(NSMutableDictionary*)ResponceJsonDictionary;
-(void)responseFailedHandller:(NSString*)ErrorDescription;

@end

///@endcond

@interface MAServerModel : NSObject
/// @cond
@property(nonatomic,strong)id<ActionDelegate> delegate;

+(id)sharedModelManager;



///@endcond
/*!
 * @discussion This method is used to ensure that an event has occured successfully.You will call to this method after calling the method
 
 \details -(void)handlingOfEventRules:(NSString *)eventId status:(NSString*)status Dictionary:(NSMutableDictionary *)dictionary;
 \details of EventManager class.
 
 \details you will implement this method like:
 \details 1.Import the framework
 \details #import <MewardInAppFrwk/MewardActionServerModel.h>
 \details 2.Make the object of the class
 
 MewardActionServerModel *mewardActionServerModel=[[MewardActionServerModel alloc] init];
 \details [mewardActionServerModel processEventSuccess:(NSString*)eventid eventstatus:@"Complete" ruleids:(NSMutableArray*)ruleids];
 
 * @param It takes eventid,eventstatus and event ruleids or tag ids as an arguments.
 
 \details Example code:
 \details EventManager *obj = [[EventManager alloc]init];
 \details if ([obj checkTimeInterval:eventId]) {
 
 \details if ([obj checkEventValidityInterval:eventId]) {
 
 \details   [obj handlingOfEventRules:eventId status:@"complete" Dictionary:dict];
 \details   [[[MewardActionServerModel alloc]init] processEventSuccess:eventId eventstatus:@"complete" ruleids:obj.ruleIdsArray];
 \details   }
 \details }
 */
-(void)onActionsuccess:(NSString*)eventid eventstatus:(NSString*)eventstatus ruleids:(NSMutableArray*)ruleids;

/*!
 * @discussion This method is used to take care of any updation in Rules and rule conditions.If there is any new rule/rule condition or both is added to existed configuration.So for this purpose you will call this service on every launch from that class where your app will go on launch.
 
 \details you will implement this method like:
 \details 1.Import the framework
 \details #import <MewardInAppFrwk/MewardActionServerModel.h>
 \details 2.Make the object of the class
 
 MewardActionServerModel *mewardActionServerModel=[[MewardActionServerModel alloc] init];
 \details [mewardActionServerModel getRuleVersion];
 
 
 */
-(void)isVersionChanged;

#pragma mark-> METHOD FOR REGISTER A RULE
/*!
 * @discussion This method is used to register a user post with respect to eventid and postId.
 * @param It takes eventid,title and postId as an arguments from the user.
 */
-(void)uniqueIdRegistar:(NSString*)eventid title:(NSString*)title postId:(NSString*)postId;

#pragma mark-> METHOD FOR updating count for a particular post
/*!
 * @discussion This method is used to update the count for a registered user post with respect to eventid and postId.
 * @param It takes eventid,mode and postId as an arguments from the user.
 */
-(void)onUniqueIdsActionPerform:(NSString*)postId eventid:(NSString*)eventid mode:(NSString*)mode;

-(void)getEventConfiguration:(NSString*)mewardId tokenkey:(NSString*)tokenKey;
-(void)storeAllEventsTags:(NSString*)mewardid TokenKey:(NSString*)tokenkey;
@end
