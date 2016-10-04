/*
 * Copyright 2015 Google Inc. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef COBALT_WEBDRIVER_ELEMENT_DRIVER_H_
#define COBALT_WEBDRIVER_ELEMENT_DRIVER_H_

#include <string>
#include <vector>

#include "base/memory/ref_counted.h"
#include "base/memory/scoped_ptr.h"
#include "base/memory/weak_ptr.h"
#include "base/message_loop_proxy.h"
#include "base/threading/thread_checker.h"
#include "cobalt/dom/element.h"
#include "cobalt/dom/keyboard_event.h"
#include "cobalt/webdriver/element_mapping.h"
#include "cobalt/webdriver/protocol/element_id.h"
#include "cobalt/webdriver/protocol/keys.h"
#include "cobalt/webdriver/protocol/search_strategy.h"
#include "cobalt/webdriver/util/command_result.h"

namespace cobalt {
namespace webdriver {

class WindowDriver;

// ElementDriver could be considered a WebElement as described in the WebDriver
// spec.
// https://code.google.com/p/selenium/wiki/JsonWireProtocol#WebElement
// Commands that interact with a WebElement, such as:
//     /session/:sessionId/element/:id/some_command
// will map to a method on this class.
class ElementDriver {
 public:
  ElementDriver(const protocol::ElementId& element_id,
                const base::WeakPtr<dom::Element>& element,
                ElementMapping* element_mapping,
                const scoped_refptr<base::MessageLoopProxy>& message_loop);
  const protocol::ElementId& element_id() { return element_id_; }

  util::CommandResult<std::string> GetTagName();
  util::CommandResult<std::string> GetText();
  util::CommandResult<bool> IsDisplayed();
  util::CommandResult<void> SendKeys(const protocol::Keys& keys);
  util::CommandResult<protocol::ElementId> FindElement(
      const protocol::SearchStrategy& strategy);
  util::CommandResult<std::vector<protocol::ElementId> > FindElements(
      const protocol::SearchStrategy& strategy);
  util::CommandResult<bool> Equals(const ElementDriver* other_element_driver);
  util::CommandResult<base::optional<std::string> > GetAttribute(
      const std::string& attribute_name);
  util::CommandResult<std::string> GetCssProperty(
      const std::string& property_name);

 private:
  typedef std::vector<scoped_refptr<dom::KeyboardEvent> > KeyboardEventVector;
  typedef std::vector<protocol::ElementId> ElementIdVector;

  // Get the dom::Element* that this ElementDriver wraps. This must be called
  // on |element_message_loop_|.
  dom::Element* GetWeakElement();

  util::CommandResult<void> SendKeysInternal(
      scoped_ptr<KeyboardEventVector> keyboard_events);

  // Shared logic between FindElement and FindElements.
  template <typename T>
  util::CommandResult<T> FindElementsInternal(
      const protocol::SearchStrategy& strategy);

  util::CommandResult<bool> EqualsInternal(
      const ElementDriver* other_element_driver);

  protocol::ElementId element_id_;

  // These should only be accessed from |element_message_loop_|.
  base::WeakPtr<dom::Element> element_;
  ElementMapping* element_mapping_;
  scoped_refptr<base::MessageLoopProxy> element_message_loop_;

  friend class WindowDriver;
};

}  // namespace webdriver
}  // namespace cobalt

#endif  // COBALT_WEBDRIVER_ELEMENT_DRIVER_H_