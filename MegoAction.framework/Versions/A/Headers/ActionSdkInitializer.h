//
//  Authentication.h
//  DataBaseStructure


#import <Foundation/Foundation.h>

/*!
 *  \brief     About This class.
 *  \details   This class is used to get configured, rules list and rule conditions list.
 */

@interface ActionSdkInitializer : NSObject

/*!
 * @discussion This method is used to add observer to observe that notification has arrived for mewardid and token key.
 \This method is called only once to get the configuration.You will call to this method first of all,may be from your AppDelegate or ViewController or whatever place you want to call but call this method before performing any event to get the configuration of events and  Rules condition List.
 
 \details you will implement this method like:
 \details 1.Import the framework
 \details #import <MewardInAppFrwk/MewardInAppFrwk.h>
 \details 2.Make the object of the class
 
 MIAResource *mIAResource=[[MIAResource alloc] init];
\details [mIAResource receiverReady];
 
\details After This it will take care of configuration
 */

-(void)initializeSdkAction;

/*!
 * @discussion This method is used to get the configuration in case of if version value changed.
 \details To detect version value is changed,we will call the method 
 -(void)getRuleVersion method of MewardActionServerModel class on every launch.
 
  \details Stepts to implement this service
 
 \details 1.Import the framework
 \details #import <MewardInAppFrwk/MewardActionServerModel.h>
 \details 2.Make the object of the class
 
 MewardActionServerModel *mewardActionServerModel=[[MewardActionServerModel alloc] init];
 \details [mewardActionServerModel getRuleVersion];
 
\details This method(getRuleVersion) posts a notification to observer class like...
 
 [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(vversionChanged:) name:@"versionChange" object:nil];
 
\details then from observer method use this code:
 
 -(void)vversionChanged:(NSNotification*)notific{
 
 \details if ([[notific name] isEqualToString:@"versionChange"]) {
\details NSString *vvalue=[[notific object] valueForKey:@"data"];
\details if (![[[NSUserDefaults standardUserDefaults] valueForKey:@"version"] isEqualToString:vvalue]) {
 
\details [[NSUserDefaults standardUserDefaults] setObject:vvalue forKey:@"version"];
\details MIAResource *mIAResource=[[MIAResource alloc] init];
 \details [mIAResource getResponse:[[NSUserDefaults standardUserDefaults] valueForKey:@"mewardIdMWI"] tokenKey:[[NSUserDefaults standardUserDefaults] valueForKey:@"tokenkeyMWI"]];
 }
 }
 
 }
 
 * @param takes mewardId and tokenKey as an argument.
 */

-(void)initializeDyanamicId:(NSString*)mewardId tokenKey:(NSString*)tokenKey;


@end
