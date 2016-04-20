

#import <Foundation/Foundation.h>

/*!
 *  \brief     About This class.
 *  \details   This class is used to take care of all the event ie what will happen on occurence of a particular event on basis of rule conditions list.
 */
@protocol ActionPerformedDelegate <NSObject>

@optional
-(void)actionSuccess;
@end

@interface MAActionPerformer : NSObject
{
    
}
@property(nonatomic,strong)id<ActionPerformedDelegate> delegate;


+(id)sharedActionManager;

/*!
 * @discussion This method is used to handle all the events like Breakfast,Lunch,Dinner etc related to meward in app ation.
 you should call this method on occurence of each event like:
 
 EventManager *obj = [[EventManager alloc]init];
 if ([obj checkTimeInterval:eventId]) {
 
 [obj handlingOfEventRules:eventId status:@"complete" Dictionary:dict];
 
 }
 
 In third dictionary argument you will pass event tagId value if that event have like calory or not then simply pass dictionary object.Make the key to tagId.
 
 BreakfastPID_Calories_MEW=@"GCX06K"
 
 NSMutableDictionary *dict = [[NSMutableDictionary alloc]init];
 [dict setValue:@"100" forKey:BreakfastPID_Calories_MEW];
 
 * @param takes eventId,status and dictionary object as an argument.
 */

-(void)onActionPerformed:(NSString *)eventId status:(NSString*)status Dictionary:(NSMutableDictionary *)dictionary;

-(void)EventsLogoutCurrentUser;

@end