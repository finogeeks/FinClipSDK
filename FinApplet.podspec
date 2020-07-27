Pod::Spec.new do |s|
  s.name         = "FinApplet"
  s.version      = "2.5.6"
  s.summary      = "凡泰小程序SDK."
  s.description  = <<-DESC
                    this is common
                   DESC
  s.homepage     = "https://mp.finogeeks.com"
  s.license      = {
    :type => 'Copyright',
    :text => <<-LICENSE
      Copyright 2017 finogeeks.com. All rights reserved.
      LICENSE
  }
  s.author             = { "developer" => "developer@finogeeks.com" }
  s.platform     = :ios, "7.0"
  s.ios.deployment_target = "8.0"
  s.source       = { :git => 'https://github.com/finogeeks/MOPLibrary.git', :tag =>"#{s.version}" }
  s.vendored_frameworks = "FinApplet.framework" 
  s.requires_arc = true
end
